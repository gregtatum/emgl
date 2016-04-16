#include <GLES2/gl2.h>

namespace emgl { namespace gl {
  struct getSourceCodeResult {
    bool error;
    char* contents;
  };
  getSourceCodeResult getSourceCode(char const *path);
  GLuint createShader(char const *source);
  GLuint createShaderFromPath(char const *path);
}}
