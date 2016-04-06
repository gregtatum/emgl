#include <emscripten.h>
#include <emscripten/html5.h>
#include "./canvas.h"

EMSCRIPTEN_WEBGL_CONTEXT_HANDLE emgl::canvas::init() {
  // Set up the attributes for the context
  EmscriptenWebGLContextAttributes attrs;
  emscripten_webgl_init_context_attributes(&attrs);
  attrs.depth = 0;
  attrs.stencil = 0;
  attrs.antialias = 0;

  // Create and append the canvas
  EM_ASM(
    Module.canvas = document.createElement('canvas');
    document.body.appendChild(Module.canvas);
  );

  // Create the context
  EMSCRIPTEN_WEBGL_CONTEXT_HANDLE gl = emscripten_webgl_create_context(0, &attrs);
  emscripten_webgl_make_context_current(gl);
  return gl;
}
