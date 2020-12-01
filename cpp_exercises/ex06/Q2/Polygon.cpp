#include "Polygon.h"
#include <cmath>

std::string Polygon::get_name() const{
    return "Polygon";
}

float Polygon::compute_area() const{
    float sum=0.f;
    for(int i=0; i<_num_vertices; ++i){
        sum += _vertices[i]._x*_vertices[(i+1)%_num_vertices]._y - _vertices[i]._y*_vertices[(i+1)%_num_vertices]._x;
    }
    return sum/2;
}

void Polygon::translate(float tx, float ty){
    for(int i=0; i<_num_vertices; ++i){
        _vertices[i]._x += tx;
        _vertices[i]._y += ty;
    }
}
