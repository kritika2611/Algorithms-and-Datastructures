/**************************************************************************************************************************************************
														COIN CHANGE
Given a set of coins, find out the minimum number of coins to make target amount.

INPUT FORMAT:
	n - total number of coins
	[] - an array consisting of all possible coins
	target - the target value

SAMPLE EXAMPLE:
3
1 7 10
15

OUTPUT:
3
*********************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int min_coin_change(int n,int *coins,int target,int dp[]){
	//base case
	if(target==0) return 0;

	if(dp[target]!=0) return dp[target];   //loookup

	//recursive case
	int min_coins=INT_MAX;
	for(int i=0;i<n;i++){
		int op=INT_MAX;
		if(target>=coins[i])
			op=min_coin_change(n,coins,target-coins[i],dp)+1;
		min_coins=min(min_coins,op);
	}
	dp[target]=min_coins;
	return dp[target];
}

int main(){
	int n; cin>>n;

	int *coins=new int[n];
	for(int i=0;i<n;i++) cin>>coins[i];

	int target; cin>>target;
	int dp[10000]={0};
	cout<<min_coin_change(n,coins,target,dp);
	return 0;
}

