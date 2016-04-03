#ifdef RUN_TESTS
#include "test/head.h"
#include "math/mat4.h"
#include "math/vec3.h"

using namespace emgl;
/*
float results[16] = {
  1.0, 0.0, 0.0, 0.0,
  0.0, 1.0, 0.0, 0.0,
  0.0, 0.0, 1.0, 0.0,
  0.0, 0.0, 0.0, 1.0,
};
*/

TEST_CASE( "identity", "emgl::mat4" ) {
  float out[16];
  float results[16] = {
    1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0,
  };
  mat4::identity(out);

  REQUIRE( shallowEquals(16, out, results) );
}

TEST_CASE( "fromTranslation", "emgl::mat4" ) {
  float identity[16]; mat4::identity(identity);
  float translation[3] = {2.0, 3.0, 5.0};
  float out[16];
  float results[16] = {
    1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    2.0, 3.0, 5.0, 1.0,
  };
  mat4::fromTranslation(out, translation);

  REQUIRE( shallowEquals(16, out, results) );
}

TEST_CASE( "multiply", "emgl::mat4" ) {
  float translationA[3] = {2.0, 3.0, 5.0};
  float translationB[3] = {7.0, 11.0, 13.0};
  float matrixA[16];
  float matrixB[16];
  float out[16];
  float results[16] = {
    1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    9.0, 14.0, 18.0, 1.0,
  };
  mat4::fromTranslation(matrixA, translationA);
  mat4::fromTranslation(matrixB, translationB);
  mat4::multiply(out, matrixA, matrixB);

  REQUIRE( shallowEquals(16, out, results) );
}

#endif
