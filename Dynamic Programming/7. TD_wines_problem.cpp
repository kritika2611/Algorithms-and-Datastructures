/*************************************************************************************************************************************************
													WINES PROBLEM
There are n different types of wines, having different prices. The price of all the wines increases per year, in 2nd year the price becomes double,
in 3rd year it becomes triple and so on..
Only one wine bottle can be sold each year, either from the start or the end of the array.
What would be the maximum profit after selling all the wines.
INPUT FORMAT:
n - number of bottles
[]- an array consisting of prices

OUTPUT FORMAT:
Max price that can obtained by selling all the wines

EXAMPLE:
Input:  5
		2 3 5 1 4

Output: 50
********************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int max_price(int i,int j,int y,int *prices,int dp[][1000]){
    if(i>j) return 0;
    if(dp[i][j]!=0) return dp[i][j];  //lookup

    //recursive case
    int op1=prices[i]*y+max_price(i+1,j,y+1,prices,dp);
    int op2=prices[j]*y+max_price(i,j-1,y+1,prices,dp);
    dp[i][j]=max(op1,op2);
    return dp[i][j];
}

int main(){
	int n; cin>>n;
	int *prices=new int[n];
	for(int i=0;i<n;i++) cin>>prices[i];   //input
    int dp[1000][1000]={0};
    cout<<max_price(0,n-1,1,prices,dp);
	return 0;
}