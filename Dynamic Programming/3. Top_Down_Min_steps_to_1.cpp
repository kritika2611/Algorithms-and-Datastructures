/**********************************************************************************************************************************************
Find the minimum steps in which you can reach 1 from n, using the following operations
n=n/3 if n%3==0
n=n/2 if n%2==0
n=n-1
********************************************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int min_steps_to_1(int n,int dp[]){
    //base case
    if(n==1) return 0;
    if(dp[n]!=0) return dp[n];   //lookup

    //recursive case
    int op1=INT_MAX, op2=INT_MAX;
    if(n%3==0) op1=min_steps_to_1(n/3,dp);
    if(n%2==0) op2=min_steps_to_1(n/2,dp);

    int op3=min_steps_to_1(n-1,dp);   //storage
    dp[n]=min(min(op1,op2),op3)+1;
    return dp[n];
}

int main() {
    int n; cin>>n;
    int dp[10000]={0};
    cout<<min_steps_to_1(n,dp);
    return 0;
}
