#include <GLES2/gl2.h>

namespace emgl { namespace gl {
  struct getSourceCodeResult {
    bool error;
    char* contents;
  };
  getSourceCodeResult getSourceCode(char const *path);
  GLuint createShader(GLenum type, char const *source);
  GLuint createShaderFromPath(GLenum type, char const *path);
  GLuint createProgram(char const *vertexPath, char const *fragmentPath);
}}
