#pragma once

namespace emgl {
namespace mat4 {
  void identity(float out[16]);
  void multiply(float out[16], float a[16], float b[16]);
  void fromTranslation(float out[16], float const v[3]);
  void log(float a[16]);
}}
