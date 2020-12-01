#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape2D.h"

class Circle : public Shape2D{
public:
    Circle(Point2D center, float radius): _center(center), _radius(radius) {}
    std::string get_name() const override;
    float compute_area() const override;
    void translate(float tx, float ty) override;
private:
    Point2D _center;
    float _radius;
};

#endif