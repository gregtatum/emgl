#include <stdio.h>
#include "vec3.h"

void emgl::vec3::add(float out[3], float const a[3], float const b[3]) {
  for (int i = 0; i < 3; i++) {
    out[i] = a[i] + b[i];
  }
}

void emgl::vec3::copy(float out[3], float const a[3]) {
  for (int i = 0; i < 3; i++) {
    out[i] = a[i];
  }
}

void emgl::vec3::cross(float out[3], float const a[3], float const b[3]) {
  float ax = a[0]; float ay = a[1]; float az = a[2];
  float bx = b[0]; float by = b[1]; float bz = b[2];

  out[0] = ay * bz - az * by;
  out[1] = az * bx - ax * bz;
  out[2] = ax * by - ay * bx;
}

void emgl::vec3::lerp(float out[3], float const a[3], float const b[3], float t) {
  float ax = a[0]; float ay = a[1]; float az = a[2];
  float bx = b[0]; float by = b[1]; float bz = b[2];

  out[0] = ax + t * (bx - ax);
  out[1] = ay + t * (by - ay);
  out[2] = az + t * (bz - az);
}

void emgl::vec3::transformMat4(float out[3], float const a[3], float const m[16]) {
  float x = a[0]; float y = a[1]; float z = a[2];
  float w = m[3] * x + m[7] * y + m[11] * z + m[15];
  if (w == 0.0) w =  1.0;

  out[0] = (m[0] * x + m[4] * y + m[8] * z + m[12]) / w;
  out[1] = (m[1] * x + m[5] * y + m[9] * z + m[13]) / w;
  out[2] = (m[2] * x + m[6] * y + m[10] * z + m[14]) / w;
}

void emgl::vec3::log(float a[3]) {
  printf(
    "Vector: %f %f %f\n",
    a[0], a[1], a[2]
  );
}
