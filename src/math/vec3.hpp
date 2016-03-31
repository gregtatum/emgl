#pragma once
namespace emgl { namespace vec3 {
  void add(float[3], floats[3], float[3]);
  void copy(float[3], float[3]);
  void cross(float[3], float[3], float[3]);
  void lerp(float[3], float[3], float);
  void transformMat4(float[3], float[3], float[16]);
  void log(float[3]);
}}
