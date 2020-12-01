//s1260145
#include <iostream>
#include "stack.h"

bool Stack::empty(){
    if(size() == -1) return true;
    else return false;
}

bool Stack::full(){
    if(size() == _max_size) return true;
    else return false; 
}

int Stack::size(){
    return _top;
}

void Stack::push(int num){
    if(full()){
        std::cout << "stack is full." << std::endl;
    }else{
        std::cout << "push " << num << std::endl;
        _data[++_top] = num;
    }
}

void Stack::pop(){
    if(empty()){
        std::cout << "stack is empty." << std::endl;
    }else{
        std::cout << "pop " << _data[_top] << std::endl;
        --_top;
    }
}

int Stack::top(){
    return _data[_top];
}