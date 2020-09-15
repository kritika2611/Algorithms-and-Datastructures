/*************************************************************************************************************************************************
															MATRIX CHAIN MULTIPLICATION

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the 
multiplications, but merely to decide in which order to perform the multiplications.
Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i]. We need to write a 
function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain.

EXAMPLES:
	Input: p[] = {40, 20, 30, 10, 30}   
	Output: 26000  
	There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
	Let the input 4 matrices be A, B, C and D.  The minimum number of 
	multiplications are obtained by putting parenthesis in following way
	(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

	Input: p[] = {10, 20, 30, 40, 30} 
	Output: 30000 
	There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
	Let the input 4 matrices be A, B, C and D.  The minimum number of 
	multiplications are obtained by putting parenthesis in following way
	((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

	Input: p[] = {10, 20, 30}  
	Output: 6000  
	There are only two matrices of dimensions 10x20 and 20x30. So there 
	is only one way to multiply the matrices, cost of which is 10*20*30

***********************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int TD_Matrix_chain_multiplication(int s,int e,int *dim,int dp[][1000]){
    //base case
    if(s>=e) return 0;
    if(dp[s][e]!=0) return dp[s][e];

    //recursive case
    int min_cost=INT_MAX;
    for(int k=s;k<e;k++){
        int a=TD_Matrix_chain_multiplication(s,k,dim,dp);
        int b=TD_Matrix_chain_multiplication(k+1,e,dim,dp);
        min_cost=min(min_cost,a+b+dim[s]*dim[k+1]*dim[e+1]);
    }
    dp[s][e]=min_cost;
    return dp[s][e];
}

int BU_MCM(int m,int *dim){
    if(m==1) return 0;

    int dp[1000][1000];
    for(int i=0;i<m;i++) dp[i][i]=0;  //base case

    int d=1;
    while(d<m){
        for(int s=0;s<m;s++){
            int e=s+d;
            if(e>=m) break;
            int min_cost=INT_MAX;
            for(int k=s;k<e;k++){
                int a=dp[s][k]+dp[k+1][e]+dim[s]*dim[k+1]*dim[e+1];
                min_cost=min(a,min_cost);
            }
            dp[s][e]=min_cost;
        }
        d+=1;
    }
    return dp[0][m-1];
}

int main() {
    int m; cin>>m;          //number of matrices
    int *dim=new int[m+1];
    for(int i=0;i<=m;i++) cin>>dim[i];

    int dp[1000][1000]={0};
    cout<<TD_Matrix_chain_multiplication(0,m-1,dim,dp)<<endl;
    cout<<BU_MCM(m,dim);
    return 0;
}


