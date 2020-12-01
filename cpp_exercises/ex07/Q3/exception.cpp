#include <stdexcept>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void doSomeComputation() {
 throw runtime_error("failure during doing some computation");
}

class Logfile{
private:
   FILE* logfile;
   char* _fname;
public:
   Logfile(char* fname) : _fname(fname){
      FILE* logfile = fopen(_fname, "w+");
      if (!logfile) throw runtime_error("failed to open file");
   }

   ~Logfile(){
      delete logfile;
      fclose(logfile);
      cout << "closing logfile" << endl;
   }

   void example(){
      fputs("log1", logfile);

      try {
         doSomeComputation();
      }
      catch (exception &e){
         throw;
      }  
   }
};

int main(void) {
 try{
    cout << "Calling example()" << endl;
    Logfile* logfile = new Logfile("logfile.txt");
    logfile->example();
    cout << "After calling example()" << endl;
 }
 catch (exception &e){
     cerr << e.what() << endl;
 }
 
 return 0;
}