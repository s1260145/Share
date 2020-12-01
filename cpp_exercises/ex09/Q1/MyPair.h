#ifndef MYPAIR
#define MYPAIR

template<class T1, class T2>
class MyPair{
public:
    T1 first;
    T2 second;
    MyPair(T1 t1, T2 t2) : first(t1), second(t2){}
};

#endif