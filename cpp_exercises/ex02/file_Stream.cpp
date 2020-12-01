#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void printAlign();

int main(){
    ifstream ifs("data.txt");
    string str;


    if(ifs.fail()){
        cout << "could not exist file" << endl;
        return 0;
    }

    int i;
    double d;
    int n=1;

    cout << "---------------------+---------------------+--------------------" << endl;
    while(getline(ifs, str)){
        i=0, d=0.0;
        sscanf(str.data(), "%d %lf", &i, &d);

        cout << setw(20) << right << n << " |";
        cout << setw(20) << right << i << " |"; 
        cout << setw(20) << right << d << endl;
        ++n;
    }


    return 0;
}