#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape2D.h"

class Rectangle : public Shape2D{
public:
    Rectangle(Point2D left_corner, float width, float height) : _left_corner(left_corner), _width(width), _height(height){}
    std::string get_name() const override;
    float compute_area() const override;
    void translate(float tx, float ty) override;
private:
    Point2D _left_corner;
    float _width;
    float _height;
};

#endif