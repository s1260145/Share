#ifndef MatNxN_H
#define MatNxN_H

#include <iostream>
using namespace std;

template<typename T, unsigned int N>
class MatNxN{
public:
    T _coefficients[N][N];

    MatNxN(){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(i == j) _coefficients[i][j] = 1;
                else _coefficients[i][j] = 0;
            }
        }
    }

    MatNxN(const T coefficients[N][N]){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                _coefficients[i][j] = coefficients[i][j];
            }
        }
    }
    
    MatNxN operator+ (const MatNxN& other){
        MatNxN ans;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                ans._coefficients[i][j] = _coefficients[i][j] + other._coefficients[i][j];
            }
        }
        return ans;
    }

    MatNxN operator- (const MatNxN& other){
        MatNxN ans;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                ans._coefficients[i][j] = _coefficients[i][j] - other._coefficients[i][j];
            }
        }
        return ans;
    }

    MatNxN operator* (const MatNxN& other){ 
        MatNxN ans;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                    ans._coefficients[i][j] = 0;
                    for(int k=0; k<N; ++k){
                        ans._coefficients[i][j] += _coefficients[i][k]*other._coefficients[k][j];
                    }
            }
        }
        return other;
    }

    MatNxN& operator+= (const MatNxN& other){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                this->_coefficients[i][j] +=  other._coefficients[i][j];
            }
        }
        return *this;
    }


    MatNxN& operator-= (const MatNxN& other){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                this->_coefficients[i][j] -=  other._coefficients[i][j];
            } 
        }
        return *this;
    }

    MatNxN& operator*= (const MatNxN& other){
        MatNxN* ans;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                ans->_coefficients[i][j] = 0;
                for(int k=0; k<N; ++k){
                ans->_coefficients[i][j] += _coefficients[i][k]*other._coefficients[k][j];
                }
            }
        }
        delete this;
        return *ans;
    }

    MatNxN operator-(){
        MatNxN ans;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                ans._coefficients[i][j] = -_coefficients[i][j];
            }
        }
        return ans; 
    }

    T operator() (const int i, const int j){
        return this->_coefficients[i][j];
    }

    bool operator==(const MatNxN& other){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(this->_coefficients[i][j] !=  other._coefficients[i][j]) return false;
            }
        }
        return true;
    }

    friend ostream& operator<<(ostream& os, MatNxN& other){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                os << other._coefficients[i][j];
            if(j!=2) os << " "; 
        }
        os << "\n";
        }
        return os;
    }
};

#endif