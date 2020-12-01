#include <iostream>
#include <cassert>
#include "MatNxN.h"

using namespace std;

int main(void) {
 MatNxN<double, 3> A; // A = I
 double coefficients[3][3] = {{1.0,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0}};
 MatNxN<double, 3> B(coefficients);


 A*B;
 MatNxN<double, 3> C = A * B;
 assert(C == B);
 

 C += B;
 C -= A;
 
 assert(C(0,0) == 1.0);
 assert(C(1,1) == 9.0);
 assert(C(2,2) == 17.0);

 MatNxN<double, 3> D = -A;
 
 assert(D(0,0) == -1.0);
 assert(D(1,1) == -1.0);
 assert(D(2,2) == -1.0);
 
 cout << "Tests passed" << endl;

 return 0;
}