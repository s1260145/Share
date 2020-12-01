#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<cassert>

using namespace std;

int calc(string str){
    stack<string> stack;

    stringstream ss(str);
    string s;
    while(ss >> s){
        if(s == "+"){
            string s1 = stack.top(); stack.pop();
            string s2 = stack.top(); stack.pop();
            stack.push(to_string(stoi(s1) + stoi(s2)));
        }
        else if(s == "-"){
            string s1 = stack.top(); stack.pop();
            string s2 = stack.top(); stack.pop();
            stack.push(to_string(stoi(s1) - stoi(s2)));
        }
        else if(s == "*"){
            string s1 = stack.top(); stack.pop();
            string s2 = stack.top(); stack.pop();
            stack.push(to_string(stoi(s1) * stoi(s2)));
        }
        else if(s == "/"){
            string s1 = stack.top(); stack.pop();
            string s2 = stack.top(); stack.pop();
            stack.push(to_string(stoi(s1) / stoi(s2)));
        }
        else {   
            stack.push(s);
        }
    }
    return stoi(stack.top());
}

int main()
{
    string input = "3 4 *";
    cout << calc(input) << endl;

    return 0;
}
