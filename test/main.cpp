#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

bool shallowEquals(int size, float a[], float b[]) {
  bool equals = true;
  for (int i = 0; i < size; i++) {
    equals = equals && a[i] == b[i];
  }
  return equals;
}

#include "math/vec3-test.cpp"
