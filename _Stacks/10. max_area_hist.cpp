#include <bits/stdc++.h>

using namespace std;

int find_max_area(int n,int hist[100]){
    stack <int> s;
    s.push(0);
    int max_area=INT_MIN;
    int i;
    
    for(i=1;i<n;i++){    
        if(hist[i]>=hist[s.top()]){
            s.push(i);
        }
        
        else{
            int area;
            while(!s.empty()&&hist[i]<hist[s.top()]){
               int curr_idx=s.top();
               s.pop();
               area=s.empty()?(hist[curr_idx]*i):(hist[curr_idx]*(i-s.top()-1));
               max_area=max(area,max_area);
           }
           s.push(i);
        }
    }
    
    //corner case
    int area;
    while(!s.empty()){
        int curr_idx=s.top();
        s.pop();
        area=s.empty()?(hist[curr_idx]*i):(hist[curr_idx]*(i-s.top()-1));
        max_area=max(area,max_area);
    }

    return max_area;
}

int main()
{
    int hist[100]={6,2,5,4,5,1,6,2};
    cout<<find_max_area(8,hist);

    return 0;
}

