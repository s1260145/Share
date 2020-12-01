#ifndef POLYGON_H
#define POLYGON_H

#include "Shape2D.h"

class Point2D;

class Polygon : public Shape2D{
public:
    Polygon(Point2D* vertices, int num_vertices) : _vertices(vertices), _num_vertices(num_vertices){}
    ~Polygon(){ delete[] _vertices; }
    std::string get_name() const override;
    float compute_area() const override;
    void translate(float tx, float ty) override;

private:
    int _num_vertices;
    Point2D* _vertices; 
    
};

#endif