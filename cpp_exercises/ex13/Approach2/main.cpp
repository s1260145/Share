#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

int main(){
    vector<int> vec;
    int n;
    cout << "input vector size >> ";
    cin >> n;
    
    cout << "input each of " << n << " elements >> ";
    for(int i=0; i<n; ++i){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    cout << "input k size >> ";
    int k;
    cin >> k;

    //calc median
    int mid=vec.size()/2;
    nth_element(vec.begin(), vec.begin()+mid, vec.end());
    float m = vec[mid];
    if(vec.size()%2 == 0){
        nth_element(vec.begin(), vec.begin() + mid-1, vec.end());
        m = 0.5*((float)vec[mid-1] + m);
    }

    //calc k-closet
    nth_element(vec.begin(), vec.begin() + k, vec.end(),
        [&m](auto& l, auto& r) { return abs((float)l-m) < abs((float)r-m); });
    
    cout << "the " << k << "-closet numbers to the median are: ";
    cout << "{";
    for(int i=0; i<k; ++i){
        cout << vec[i];
        if(i!=k-1)cout <<", ";
    }
    cout << "}" << endl;

    return 0;
}