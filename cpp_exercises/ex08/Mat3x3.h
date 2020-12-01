#ifndef MAT3X3_H
#define MAT3X3_H

#include <iostream>
using namespace std;

class Mat3x3{
private:
    double _coefficients[3][3];

public:
    Mat3x3();
    Mat3x3(const double coefficients[3][3]);
    
    Mat3x3 operator+ (const Mat3x3& other);
    Mat3x3 operator- (const Mat3x3& other);
    Mat3x3 operator* (const Mat3x3& other);
    Mat3x3& operator+= (const Mat3x3& other);
    Mat3x3& operator-= (const Mat3x3& other);
    Mat3x3& operator*= (const Mat3x3& other);
    Mat3x3 operator-();
    double operator() (const int i, const int j);
    bool operator==(const Mat3x3& other);
    friend ostream& operator<<(ostream& os, Mat3x3& other);
};

#endif