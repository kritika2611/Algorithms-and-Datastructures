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

int max_price(int n,int *prices){
    int dp[1000][1000]={0};
    //base case
    for(int i=0;i<n;i++) dp[i][i]=prices[i]*n;

    int d=1;
    while(d<n){
        for(int i=0;i<n;i++){
            int j=i+d;
            if(j>n-1) break;

            int y=n-(j-i);
            int op1=prices[i]*y+dp[i+1][j];
            int op2=prices[j]*y+dp[i][j-1];
            dp[i][j]=max(op1,op2);
        }
        d++;
    }
    return dp[0][n-1];
}

int main(){
	int n; cin>>n;
	int *prices=new int[n];
	for(int i=0;i<n;i++) cin>>prices[i];   //input
    cout<<max_price(n,prices);
	return 0;
}