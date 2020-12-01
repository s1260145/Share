#ifndef POINT2D_H
#define POINT2D_H

#include <string>

class Point2D{
public:   
    float _x, _y;
    Point2D(float x, float y): _x(x), _y(y) {}
};

class Shape2D{
public:
    virtual ~Shape2D(){}
    virtual std::string get_name() const=0;
    virtual float compute_area() const=0;
    virtual void translate(float tx, float ty)=0;
};

#endif