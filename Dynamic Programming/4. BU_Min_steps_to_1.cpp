/**********************************************************************************************************************************************
Find the minimum steps in which you can reach 1 from n, using the following operations
n=n/3 if n%3==0
n=n/2 if n%2==0
n=n-1
********************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int min_steps_to_1(int n){
    if(n==1) return 0;

    int dp[10000]={0};
    dp[1]=0;   //base case
    for(int i=2;i<=n;i++){
        int op1=INT_MAX, op2=INT_MAX;
        if(i%3==0) op1=dp[i/3];
        if(i%2==0) op2=dp[i/2];
        int op3=dp[i-1];
        dp[i]=min(op1,min(op2,op3))+1; //storage
    }
    return dp[n];
}

int main() {
    int n; cin>>n;
    cout<<min_steps_to_1(n);
    return 0;
}
