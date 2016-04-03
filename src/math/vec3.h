#pragma once
namespace emgl { namespace vec3 {
  void add(float out[3], float const a[3], float const b[3]);
  void copy(float out[3], float const a[3]);
  void cross(float out[3], float const a[3], float const b[3]);
  void lerp(float out[3], float const a[3], float const b[3], float t);
  void transformMat4(float out[3], float const a[3], float const m[16]);
  void log(float a[3]);
}}
