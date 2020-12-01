#include "Rectangle.h"

using namespace std;

string Rectangle::get_name() const{
    return "Rectangle";
}

float Rectangle::compute_area() const{
    return _width*_height;
}

void Rectangle::translate(float tx, float ty){
    _left_corner._x += tx;
    _left_corner._y += ty;
}