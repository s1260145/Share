#include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

void doSomeComputation() {
 throw runtime_error("failure during doing some computation");
}

void example() {
 FILE* logfile = fopen("logfile.txt", "w+");
 if (!logfile) {
   throw runtime_error("failed to open file");
 }

 fputs("log1", logfile);

 // call a function that performs some computation and may throw 
 // an exception
 try {
    doSomeComputation();
 }
 catch (exception &e){
    delete logfile;
    fclose(logfile);
    throw;
 }
cout << "closing logfile" << endl;
}

int main(void) {
 try{
    cout << "Calling example()" << endl;
    example();
    cout << "After calling example()" << endl;
 }
 catch (exception &e){
     cerr << e.what() << endl;
 }
 
 return 0;
}