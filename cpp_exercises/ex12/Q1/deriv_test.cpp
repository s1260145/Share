#include<iostream>
#include<functional>

using namespace std;

function<double(double)> deriv(function<double(double)> f){
    return [=](double x){
        double epsilon = 0.00000095367431640625;
        return (f(x+epsilon) - f(x-epsilon))/(2.0*epsilon);
    };
}

function<double(double)> f = ([](double x) { return x;});

int main(void) 
{
    auto df = deriv([](double x) { return x; });
    cout << df(1.0) << endl; // should be 1
    cout << df(2.0) << endl; // should be 1
}