#include<iterator>
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream file("numbers.txt");
    ostream_iterator<int> osi(file, "\n");
    istream_iterator<int> isi(cin);

    while(isi != istream_iterator<int>()){
        if(*isi%3 == 0 && *isi%5 != 0) *osi = *isi;
        ++isi;
    }
    
    return 0;
}