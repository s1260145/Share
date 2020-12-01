#include "Circle.h"


const float PI = 3.141593f;

using namespace std;

string Circle::get_name() const{
    return "Circle";
}

float Circle::compute_area() const{
    return _radius*_radius*PI;
}

void Circle::translate(float tx, float ty){
    _center._x += tx;
    _center._y += ty;
}