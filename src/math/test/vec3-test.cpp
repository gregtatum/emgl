#ifdef RUN_TESTS
#include "test/head.h"
#include "math/mat4.h"
#include "math/vec3.h"

TEST_CASE( "add", "emgl::vec3" ) {
  float out[3] = {0.0, 0.0, 0.0};
  float a[3] = {1.0,2.0,3.0};
  float b[3] = {5.0,7.0,9.0};
  float result[3] = {6.0, 9.0, 12.0};

  emgl::vec3::add(out, a, b);
  REQUIRE( shallowEquals(3, out, result) );
}

TEST_CASE( "copy", "emgl::vec3" ) {
  float out[3] = {0.0, 0.0, 0.0};
  float a[3] = {1.0,2.0,3.0};

  emgl::vec3::copy(out, a);
  REQUIRE( shallowEquals(3, out, a) );
}

TEST_CASE( "cross", "emgl::vec3" ) {
  float out[3] = {0.0, 0.0, 0.0};
  float a[3] = {1.0,2.0,3.0};
  float b[3] = {5.0,7.0,9.0};
  float result[3] = {-3.0, 6.0, -3.0};

  emgl::vec3::cross(out, a, b);
  REQUIRE( shallowEquals(3, out, result) );
}

TEST_CASE( "lerp", "emgl::vec3" ) {
  float out[3] = {0.0, 0.0, 0.0};
  float a[3] = {1.0,2.0,3.0};
  float b[3] = {5.0,7.0,9.0};
  float resultA[3] = {2.0, 3.25, 4.5};
  float resultB[3] = {3.0, 4.5, 6.0};
  float resultC[3] = {4.0, 5.75, 7.5};

  emgl::vec3::lerp(out, a, b, 0.25);
  REQUIRE( shallowEquals(3, out, resultA) );
  emgl::vec3::lerp(out, a, b, 0.50);
  REQUIRE( shallowEquals(3, out, resultB) );
  emgl::vec3::lerp(out, a, b, 0.75);
  REQUIRE( shallowEquals(3, out, resultC) );
}

TEST_CASE( "transformMat4", "emgl::vec3" ) {
  float out[3] = {0.0, 0.0, 0.0};
  float a[3] = {1.0,2.0,3.0};
  float b[3] = {5.0,7.0,9.0};
  float m[16];
  float result[3] = {6.0, 9.0, 12.0};

  emgl::mat4::fromTranslation(m, b);
  emgl::vec3::transformMat4(out, a, m);

  REQUIRE( shallowEquals(3, out, result) );
}
#endif
