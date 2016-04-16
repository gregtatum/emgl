#include <GLES2/gl2.h>
#include <stdio.h>
#include "./shaders.h"

using namespace emgl::gl;

GLuint emgl::gl::createShader(char const *source) {
  // Create and compile the shader
  GLuint shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(shader, 1, &source, NULL);
  glCompileShader(shader);

  // Check compilation status
  GLint isCompiled = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
  if(isCompiled == GL_FALSE){
    GLint maxLength = 2000;
    char errorLog[maxLength];

    // Get the shader info
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
    glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);

    printf("%s\n", errorLog);
    glDeleteShader(shader);
  } else {
    printf("shader successfully compiled\n");
  }

  return shader;
}

getSourceCodeResult emgl::gl::getSourceCode(char const path[]) {
  getSourceCodeResult result;

  FILE *filePointer = fopen(path , "rb");
  if(!filePointer) {
    perror(path);
    result.error = true;
    return result;
  }

  // Get the length of the file
  fseek(filePointer, 0L, SEEK_END);
  long fileSize = ftell(filePointer);
  rewind(filePointer);

  result.contents = new char[fileSize + 1];
  result.contents[fileSize] = 0;

  // Copy the file into the `result.contents`
  if(fread(result.contents , fileSize, 1, filePointer) != 1) {
    fclose(filePointer);
    fputs("read file failed", stderr);
    result.error = true;
    return result;
  }

  result.error = false;
  fclose(filePointer);
  return result;
}

GLuint emgl::gl::createShaderFromPath(char const *path) {
  // Grab the source code
  getSourceCodeResult sourceCodeResult = emgl::gl::getSourceCode(path);
  if(sourceCodeResult.error) {
    return 0;
  }

  // Create the shader
  GLuint shader = emgl::gl::createShader(sourceCodeResult.contents);
  delete [] sourceCodeResult.contents;
  return shader;
}
