#define NUMBER_POINTS 1000
#include "./points.h"

using namespace emgl::gl;

GLuint emgl::gl::createGLBuffer(GLenum target,
                              const void *buffer_data,
                              GLsizei buffer_size) {
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(target, buffer);
    glBufferData(target, buffer_size, buffer_data, GL_STATIC_DRAW);
    return buffer;
}

Buffer emgl::gl::makePoints() {
  Buffer points;
  points.data = new GLfloat[NUMBER_POINTS * 3]();
  points.buffer = emgl::gl::createGLBuffer(
    GL_ARRAY_BUFFER,
    points.data,
    sizeof(points.data)
  );

  return points;
}
