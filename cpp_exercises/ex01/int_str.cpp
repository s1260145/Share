//s1260145
#include "int_str.h"
#include <stdlib.h>

char* intToStr(int num){
    int sign=1;
    if(num < 0){
        num*=-1;
        sign=-1;
    }

    //Count digits
    int tmp=num;
    int digit;
    for(digit=1; tmp>=10; ++digit) tmp=tmp/10;
    if(sign==-1) digit+=1;
    
    //Since the end is a null character, plus 1 byte
    char* str=(char*)malloc(digit+1);
    str[digit]='\0';

    for(int i=digit-1; i>=0; --i){
        str[i] = ('0' + (num%10));
        num/=10;
    }
    if(sign==-1) str[0]='-';

    return str;
}

int strToInt(char* str){
    int sign = 1;
    int i=0;
    if (str[0] == '-') {
        sign = -1;
        ++i;
    }

    int num=0;
    while ((str[i] >= '0') && (str[i] <= '9'))
    {
        num *= 10;
        num += (int)str[i] - '0';
        ++i;
    }

    return num * sign;
}