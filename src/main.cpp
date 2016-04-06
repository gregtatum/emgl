#ifndef RUN_TESTS
#include <stdio.h>
#include <emscripten.h>
#include "math/vec3.h"
#include "math/mat4.h"
#include "canvas.h"

int main() {
  float mat[16];
  float a[3] = {10.0,200.0,30.0};

  emgl::mat4::fromTranslation(mat, a);
  emgl::mat4::log(mat);

  EM_ASM_ARGS({
    var div = document.createElement("div");
    document.body.appendChild(div);
    var ghost = document.createElement("div");
    document.body.appendChild(ghost);

    var matrix = toFloatArray(16, $0);
    console.log("Address location:", $0);
    console.log("Array", matrix);
    console.log("Matrix", "matrix3d(" + matrix.join(",") +")");
    var baseStyle = ({
      width: "100px",
      height: "100px",
      background: "red",
      position: "absolute",
      top: '20px',
      bottom: '20px'
    });

    Object.assign(div.style, baseStyle, {
      transform: "matrix3d(" + matrix.join(",") +")"
    });

    Object.assign(ghost.style, baseStyle, {
      opacity: "0.3"
    });

    function toFloatArray(length, address) {
      var arr = Array(length);
      for (let i = 0; i < length; i++) {
        arr[i] = Module.HEAPF32[address/4 + i];
      }
      return arr;
    }
  }, mat);

  emgl::canvas::init();

  return 0;
}
#endif
