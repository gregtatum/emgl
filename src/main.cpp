#ifndef RUN_TESTS
#include <stdio.h>
#include "math/vec3.h"
#include "math/mat4.h"

int main() {
  float mat[16];
  float out[4] = {0.0,0.0,0.0,0.0};
  float a[3] = {1.0,2.0,3.0};
  float b[3] = {1.0,2.0,3.0};

  emgl::vec3::add(out, a, b);
  emgl::vec3::log(out);

  emgl::mat4::fromTranslation(mat, a);
  emgl::mat4::log(mat);

  return 0;
}
#endif
