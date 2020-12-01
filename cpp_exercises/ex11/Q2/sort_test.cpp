#include<iostream>
#include<vector>

using namespace std;

template <class Ran>
void sort(Ran begin, Ran end){
    int n = end - begin;
    for(int i=0; i<n; ++i){
        for(int j=n-1; j>=i+1; --j){
            if(begin[i] > begin[j-1]) swap(begin[i], begin[j-1]);
        }
    }
}


int main(){
    vector<int> vec{7, 3 , 9, 2, 5, 1, 5, 3, 12};
    sort(vec.begin(), vec.end());

    for(auto n : vec) cout << n << " ";
    cout << endl;

    return 0;
}