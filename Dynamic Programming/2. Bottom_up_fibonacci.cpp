#include <bits/stdc++.h>
using namespace std;

long long fib(int n){
    long long dp[1000]={0};
    //base cases
    dp[0]=0; dp[1]=1;

    for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];

    return dp[n];
}

long long fib_space_optimized(int n){
    if(n==0 || n==1) return n;

    long long a,b,ans;
    a=0;
    b=1; 
    for(int i=2;i<=n;i++) {
        ans=a+b;
        a=b;
        b=ans;
    }
    return ans;
}

int main() {
    int n; cin>>n;
    cout<<fib(n)<<endl;
    cout<<fib_space_optimized(n);
    return 0;
}
