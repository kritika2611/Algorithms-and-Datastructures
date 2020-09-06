/**************************************************************************************************************************************************
														COIN CHANGE
Given a set of coins, find out the minimum number of coins to make target amount.

INPUT FORMAT:
t - total number of test cases
for each test case:	n - total number of coins
                    [] - an array consisting of all possible coins
                    target - the target value

SAMPLE EXAMPLE:
3

9
1 2 5 10 20 50 100 200 500
39

3
1 7 10
15

3
1 3 5
8

OUTPUT:
5
3
2
*********************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int min_coin_change(int n,int *coins,int target){
	int dp[10000]={0};
    dp[0]=0; //base case

    for(int i=1;i<=target;i++){
        int min_coins=INT_MAX;
        for(int j=0;j<n;j++){
            if(i>=coins[j]){
                int c=coins[j];
                min_coins=min(min_coins, dp[i-c]+1);
            }
        }
        dp[i]=min_coins;
    }

    return dp[target];
}

int main(){
    int t; cin>>t;
	while(t--){
        int n; cin>>n;
        int *coins=new int[n];
        for(int i=0;i<n;i++) cin>>coins[i];

        int target; cin>>target;
        cout<<min_coin_change(n,coins,target)<<endl;
    }
	return 0;
}

