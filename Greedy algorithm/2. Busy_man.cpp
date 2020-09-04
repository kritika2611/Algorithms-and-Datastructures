/*****************************************************************************************************************************************
                         					ACTIVITES SELECTION

Given n activities, with their starting and ending time.
Find the maximum number of activities you can complete in a given time.

INPUT:  6
		7 9
		0 10
		4 5
		8 9
		4 10
		5 7
OUTPUT: 3
***************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool comp(pair <int,int> p1, pair<int,int> p2){
    return p1.second<p2.second;
}

int main() {
    int n;
    cin>>n;
    pair <int,int> *p=new pair<int,int>[n];
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        p[i]=make_pair(s,e);
    }
    
    sort(p,p+n,comp);

    int e=p[0].second;
    int ans=1;
    for(int i=1;i<n;i++){
        int s=p[i].first;
        if(s>=e){
            ans+=1;
            e=p[i].second;
        }
    }    
    cout<<ans<<endl;

    return 0;
}
