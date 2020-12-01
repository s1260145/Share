// COMPLETE include the necessary headers here
#include "Shape2D.h"
#include "Rectangle.h"
#include "Circle.h"
#include <cmath>
#include <cassert>

inline void assertFloat(float x, float y, float eps=1e-5) {
    assert(std::fabs(x-y) < eps);
}

const float PI = 3.141593f;

int main(void) {
  const int NUM_SHAPES = 2;
  Shape2D* shapes[NUM_SHAPES];
  Point2D center(0.0f, 0.0f);
  shapes[0] = new Circle(center, 1.0f);

  Point2D left_corner(-1.0f, -1.0f);
  shapes[1] = new Rectangle(left_corner, 4.0f, 2.0f);

  for (int i = 0; i < NUM_SHAPES; ++i) {
    float tx = 1.0f;
    float ty = -1.0f;
    shapes[i]->translate(tx, ty);
  }

  assertFloat(shapes[0]->compute_area(), PI);
  assertFloat(shapes[1]->compute_area(), 8.0);

  delete[] shapes;

  return 0;
}