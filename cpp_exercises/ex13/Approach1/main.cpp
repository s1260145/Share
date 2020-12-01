#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

float compute_median(vector<int> vec){
    float ans;
    int tmp=vec.size()/2;
    if(vec.size()%2==0) ans = ((float)vec[tmp-1] + (float)vec[tmp])/2.0;
    else ans = vec[tmp];
    return ans;
}

struct CompareDistMedian{
    bool operator()(pair<float, float> p1, pair<float, float> p2){
        return p1.second > p2.second;
    }
};

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


    sort(vec.begin(), vec.end());
    float m = compute_median(vec);
    priority_queue<pair<float, float>, vector<pair<float, float>>, CompareDistMedian> pq;
    for(auto& e : vec) pq.push({e, abs((float)e-m)});
    
    
    cout << "the " << k << "-closet numbers to the median are: ";
    cout << "{";
    for(int i=0; i<k; ++i){
        cout << pq.top().first;
        pq.pop();
        if(i!=k-1)cout <<", ";
    }
    cout << "}" << endl;

    return 0;
}