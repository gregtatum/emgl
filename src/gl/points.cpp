#include "./points.h"
#include <stdlib.h>
#include <stdio.h>

using namespace emgl::gl;

GLuint emgl::gl::createGLBuffer(GLenum target, const void *buffer_data,
                                GLsizei buffer_size) {
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(target, buffer);
    glBufferData(target, buffer_size, buffer_data, GL_DYNAMIC_DRAW);
    return buffer;
}

Buffer * emgl::gl::makePoints(unsigned int const length) {
  Buffer *points = new Buffer;
  points->length = length;
  points->data = new GLfloat[length * 3]();
  points->buffer = emgl::gl::createGLBuffer(
    GL_ARRAY_BUFFER,
    points->data,
    sizeof(points->data)
  );

  return points;
}


float emgl::gl::randomFloat() {
  return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void emgl::gl::updatePoints(Buffer *points) {
  for (int i=0; i < points->length; i++) {
    points->data[i*3] = emgl::gl::randomFloat() * 2.0 - 1.0;
    points->data[i*3+1] = emgl::gl::randomFloat() * 2.0 - 1.0;
    points->data[i+3+2] = emgl::gl::randomFloat() * 2.0 - 1.0;
  }
}

void emgl::gl::draw(void * _args) {
  DrawArgs *args = static_cast<DrawArgs*>(_args);
  Buffer *points = args->points;
  GLuint program = args->program;

  glUseProgram(program);

  static const unsigned int FLOAT = 4;
  static const unsigned int DIMENSIONS = 3;

  emgl::gl::updatePoints(points);

  glClear(GL_COLOR_BUFFER_BIT);
  // glEnableClientState(GL_VERTEX_ARRAY);
  glBindBuffer(GL_ARRAY_BUFFER, points->buffer);
  glBufferData(GL_ARRAY_BUFFER, (points->length * FLOAT * DIMENSIONS),
               points->data, GL_DYNAMIC_DRAW);
  glVertexAttribPointer(0, DIMENSIONS, GL_FLOAT, 0, FLOAT * DIMENSIONS, 0);
  glEnableVertexAttribArray(0);
  glDrawArrays(GL_POINTS, 0, points->length);
}
