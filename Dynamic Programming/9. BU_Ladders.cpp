/******************************************************************************************************************************************
Given n steps. Find out the number of ways a person can reach nth step, by taking at max k step at each level

Input:  n=4
		k=3
Output: 7
*******************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int total_ways(int n,int k){
    if(n==0 || n==1) return 1;

    int dp[10000]={0};
    //base case
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j >=0 ) dp[i]+=dp[i-j];
            else break;
        }
    }
    return dp[n];
}

int main() {
    int n; cin>>n;
    int k; cin>>k;
    cout<<total_ways(n,k);
    return 0;
}
