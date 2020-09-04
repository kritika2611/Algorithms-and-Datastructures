#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue <int> pq;   // by default= max_heap
    priority_queue <int,vector<int>,greater<int>> pq1;    //min heap
    int n; cin>>n;
    while(n--){
        int e;
        cin>>e;
        pq.push(e);    // O(logn)
        pq1.push(e);
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    while(!pq1.empty()){
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    return 0;
}
