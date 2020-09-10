/******************************************************  ROD CUT *****************************************************************************
Given a rod of length n and an array consisting of prices of rod length. i.e, [2,3,3,4] represents 2 is the price of length1, 3 the price for 
length 2, 3 for length 3 and so on.
Find the max profit that can be obtained by cutting the rod and selling the pieces.

SAMPLE INPUT:
n- 4
prices- 2 3 2 4

SAMPLE OUTPUT: 8

EXPLANATION: The rod of length 4 ca be cutted as follow-
(4) -> profit=5
(3,1) -> profit=4
(2,1,1) -> profit=7
(2,2) -> profit=6
(1,1,1,1) -> profit=8
from the above arrangeent max profit is 8rs
********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int max_profit_TD(int n,int len_prices[],int dp[]){
    //base case
    if(n==0) return 0;
    if(dp[n]!=0) return dp[n];
    //recursive case
    int max_profit=INT_MIN;
    for(int i=1;i<=n;i++){
        int profit=len_prices[i]+max_profit_TD(n-i,len_prices,dp);
        max_profit=max(profit,max_profit);
    }
    dp[n]=max_profit;
    return dp[n];
}

int max_profit_BU(int n,int len_prices[]){
    if(n==0) return 0;
    int dp[10000]={0};
    dp[0]=0;  //base case
    for(int i=1;i<=n;i++){
        int best=INT_MIN;
        for(int cut=1;cut<=i;cut++){
            int profit=len_prices[cut]+dp[i-cut];
            best=max(best,profit);
        }
        dp[i]=best;
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int len_prices[1000]={0};
    for(int i=1;i<=n;i++) cin>>len_prices[i];

    cout<<max_profit_BU(n,len_prices)<<endl;
    int dp[10000]={0};
    cout<<max_profit_TD(n,len_prices,dp);
    return 0;
}