#include <GLES2/gl2.h>

namespace emgl { namespace gl {

  GLuint createGLBuffer(
    GLenum target,
    const void *buffer_data,
    GLsizei buffer_size
  );

  struct Buffer {
    GLfloat * data;
    GLuint buffer;
    unsigned int length;
  };
  struct DrawArgs {
    Buffer * points;
    GLuint program;
  };
  float randomFloat();
  void updatePoints(Buffer * points);
  void draw(void * _points);

  Buffer * makePoints(unsigned int const length);
}}
