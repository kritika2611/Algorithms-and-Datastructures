/****************************************************	LONGEST COMMON SUBSEQUENCE  ***************************************************************
Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative
order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”\

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
****************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int BU_LCS(string s1,string s2){
    if(s1.empty() || s2.empty()) return 0;

    s1=" "+s1;
    s2=" "+s2;
    int n=s1.length();
    int m=s2.length();
    int dp[1000][1000]={0};  //base case-> 0th row and 0th column=0
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(s1[i]==s2[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}

int TD_LCS(int i,int j,string s1,string s2,int dp[][1000]){
    //base case
    if(i==s1.size() || j==s2.size()) return 0;
    if(dp[i][j]!=0) return dp[i][j];    //lookup

    //recursive case
    if(s1[i]==s2[j]) dp[i][j]=1+TD_LCS(i+1,j+1,s1,s2,dp);
    else{
        int op1=TD_LCS(i+1,j,s1,s2,dp);
        int op2=TD_LCS(i,j+1,s1,s2,dp);
        dp[i][j]=max(op1,op2);
    }
    return dp[i][j];
}


int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<BU_LCS(s1,s2)<<endl;
    int dp[1000][1000]={0};
    cout<<TD_LCS(0,0,s1,s2,dp)<<endl;
    return 0;
}
