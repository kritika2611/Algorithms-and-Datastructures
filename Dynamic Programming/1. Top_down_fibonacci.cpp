#include <bits/stdc++.h>
using namespace std;

long long fib(int n,int dp[]){
    //base case
    if(n==0 || n==1) return n;

    if(dp[n]!=0) return dp[n];   //lookup

    //recursive case
    long long ans=fib(n-2,dp)+fib(n-1,dp);
    dp[n]=ans;     //storage
    return ans;
}

int main() {
    int n; cin>>n;

    int dp[1000]={0};
    cout<<fib(n,dp)<<endl;
    return 0;
}
