#include<stdio.h>
#include "math/vec3.cpp"
#include "math/mat4.cpp"

int main() {
  float mat[16];
  float out[4] = {0.0,0.0,0.0,0.0};
  float a[4] = {1.0,2.0,3.0,4.0};
  float b[4] = {1.0,2.0,3.0,4.0};

  emgl::vec3::add(out, a, b);
  emgl::vec3::log(mat);

  emgl::mat4::fromTranslation(mat, a);
  emgl::mat4::log(mat);

  return 0;
}
