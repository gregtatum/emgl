#ifndef RUN_TESTS
#include <stdio.h>
#include <emscripten.h>
#include "canvas.h"
#include "gl/shaders.h"
#include "gl/points.h"

int main() {

  //EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx =
  emgl::canvas::init();

  emgl::gl::DrawArgs drawArgs;
  drawArgs.points = emgl::gl::makePoints(1000);
  drawArgs.program = emgl::gl::createProgram(
    "src/shaders/points.vert",
    "src/shaders/points.frag"
  );

  emscripten_set_main_loop_arg(emgl::gl::draw, &drawArgs, 0, 0);
}
#endif
