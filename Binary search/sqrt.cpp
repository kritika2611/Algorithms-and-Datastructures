#include <bits/stdc++.h>

using namespace std;

float sqrt_(int n,int p){
    //find int part
    int s=0;
    int e=n;
    float ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(mid*mid==n){
            ans=mid;
            break;
        }
        else if((mid*mid)>n)
            e=mid-1;
        else{
            s=mid+1;
            if(mid>ans || ans==-1)
                ans=mid;
        }
    }
    
    //find decimal part-- brute force
    float inc=0.1;
    
    for(int i=1;i<=p;i++){
        while(ans*ans<=n){
            ans=ans+inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    
    return ans;
    
}

int main()
{
    int N,p;
    cin>>N;
    cin>>p;
    
    cout<<sqrt_(N,p);

    return 0;
}
