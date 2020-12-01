//s1260145
#include <iostream>
#include <string>

int hanoi(int n, std::string a, std::string b, std::string c);

int main(int argc, char** argv) {
  if (argc!=2) {
    std::cout << "Usage: " << argv[0] << " n" << std::endl;
    std::cout << "where n is the number of disks." << std::endl;
    return 1;
  }

  int n = std::stoi(argv[1]); // convert the argv[1] to an int

  std::cout << hanoi(n, "src", "dst", "work") << std::endl;
}

int hanoi(int n, std::string a, std::string b, std::string c){
    int cnt=0;
    if(n==0) return 0;

    cnt+=hanoi(n-1, a, c, b);
    std::cout << a << " -> " << b << std::endl;
    cnt+=hanoi(n-1, c, b, a);
    return cnt+1;
}