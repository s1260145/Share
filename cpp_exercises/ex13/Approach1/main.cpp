#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

float compute_median(vector<int> vec){
    float ans;
    int tmp=vec.size()/2;
    if(vec.size()%2==0) ans = ((float)vec[tmp-1] + (float)vec[tmp])/2.0;
    else ans = vec[tmp];
    return ans;
}

float m;
int k;
struct CompareDistMedian{
    bool operator()(int l, int r){
        return abs((float)l-m) > abs((float)r-m);
    }
};

vector<int> compute_k_closet(vector<int> vec){
    priority_queue<int, vector<int>, CompareDistMedian> pq;
    for(auto& e : vec) pq.push(e);
    vector<int> ans;
    for(int i=0; i<k; ++i){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}



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
    cin >> k;

    sort(vec.begin(), vec.end());
    m = compute_median(vec);
    vector<int> ans = compute_k_closet(vec);
    
    cout << "the " << k << "-closet numbers to the median are: ";
    cout << "{";
    for(int i=0; i<k; ++i){
        cout << ans[i];
        if(i!=k-1)cout <<", ";
    }
    cout << "}" << endl;

    return 0;
}