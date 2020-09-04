#include <bits/stdc++.h>

using namespace std;

int profit(int n,int c,int *w,int *p){
    //base case
    if(n==0 || c==0)
        return 0;
        
    //recursive case
    int x,y;
    x=y=INT_MIN;
    if(c-w[n-1]>=0)
        x=p[n-1]+profit(n-1,c-w[n-1],w,p);
        
    y=profit(n-1,c,w,p);
    
    return max(x,y);
}

int main()
{
    int n,c;
    cin>>n;
    int *w=new int[n];
    for(int i=0;i<n;i++)
        cin>>w[i];
        
    int *p=new int[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    
    cin>>c;
    
    cout<<profit(n,c,w,p);
    
    return 0;
}
