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
  };

  Buffer makePoints();


}}
