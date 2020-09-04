#include <bits/stdc++.h>

using namespace std;

int *find_span(int n,int price[]){
    stack <pair<int,int>> stk;
    int *span=new int[n];
    
    stk.push(make_pair(0,price[0]));
    span[0]=1;
    
    for(int i=1;i<n;i++){
        int curr_price=price[i];
        
        while(!stk.empty() and stk.top().second<=curr_price){
            stk.pop();
        }
        
        if(stk.empty()){
            span[i]=i+1;
        }
        else{
            int idx=stk.top().first;
            span[i]=i-idx;
        }
        
        //add current element
        stk.push(make_pair(i,price[i]));
    }
    
    return span;
}


int main()
{
    int price[]={100,80,60,70,60,75,185};
    int n=sizeof(price)/sizeof(price[0]);
    
    int *span=find_span(n,price);
    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }
    
    return 0;
}

