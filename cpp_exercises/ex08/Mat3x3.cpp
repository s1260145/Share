#include "Mat3x3.h"

Mat3x3::Mat3x3(){
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            if(i == j) _coefficients[i][j] = 1;
             else _coefficients[i][j] = 0;
        }
    }
}

Mat3x3::Mat3x3(const double coefficients[3][3]){
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            _coefficients[i][j] = coefficients[i][j];
        }
    }
}

Mat3x3 Mat3x3::operator+ (const Mat3x3& other){
    Mat3x3 ans;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            ans._coefficients[i][j] = _coefficients[i][j] + other._coefficients[i][j];
        }
    }
    return ans;
}

Mat3x3 Mat3x3::operator- (const Mat3x3& other){
    Mat3x3 ans;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            ans._coefficients[i][j] = _coefficients[i][j] - other._coefficients[i][j];
        }
    }
    return ans;
}
    

Mat3x3 Mat3x3::operator* (const Mat3x3& other){
    Mat3x3 ans;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            ans._coefficients[i][j] = 0;
            for(int k=0; k<3; ++k){
                ans._coefficients[i][j] += _coefficients[i][k]*other._coefficients[k][j];
            }
        }
    }
    return ans;
}

Mat3x3& Mat3x3::operator+= (const Mat3x3& other){
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            this->_coefficients[i][j] +=  other._coefficients[i][j];
        }
    }
    return *this;
}

Mat3x3& Mat3x3::operator-= (const Mat3x3& other){
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            this->_coefficients[i][j] -=  other._coefficients[i][j];
        } 
    }
    return *this;
}

Mat3x3& Mat3x3::operator*= (const Mat3x3& other){
    Mat3x3* ans;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            ans->_coefficients[i][j] = 0;
            for(int k=0; k<3; ++k){
                ans->_coefficients[i][j] += _coefficients[i][k]*other._coefficients[k][j];
            }
        }
    }
    delete this;
    return *ans;
}

Mat3x3 Mat3x3::operator-() {
    Mat3x3 ans;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            ans._coefficients[i][j] = -_coefficients[i][j];
        }
    }
    return ans;
}

double Mat3x3::operator() (const int i, const int j){
    return this->_coefficients[i][j];
}

bool Mat3x3::operator== (const Mat3x3& other){
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            if(this->_coefficients[i][j] !=  other._coefficients[i][j]) return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& os, Mat3x3& other){
   for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            os << other._coefficients[i][j];
            if(j!=2) os << " "; 
        }
        os << "\n";
   }
   return os;
}