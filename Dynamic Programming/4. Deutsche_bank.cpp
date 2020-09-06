/*************************************************************************************************************************************************
														ESCAPE TRAPS
Given a string s containing '#'' and '*', Where # represents safe cell and * represents a trap.
from any cell i we can have the three possible moves(initially you are on cell 1):
i -> i+1
i -> i+2 
i -> i+A  if A/i >= r1/r2
where A is the total number of prime numbers from 1,2,3......i

Find the minimum number of moves to reach the nth cell.

INPUT FORMAT:
t = number of test cases
for each test case: r1 r2
					n(size of string)
					string

OUTPUT:
minimum number of steps to reach last cell
if it is not possible return "No way!"


INPUT:  4
		1 2
		8
		########
		1 5
		5
		#***#
		2 3
		11
		#*#*#*#*#*#
		1 2
		10
		#*###**###

OUTPUT: 3
		No way!
		5
		4

***********************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int Prime_check(int i){
    if(i<=1) return 0;
    if(i<=3) return 1;

    if(i%3==0 || i%2==0) return 0;

    for(int k=5;k*k<=i;k++){
        if(i%k==0 || i%(k+2)==0) return 0;
    }
    
    return 1;
}

string trap_sol (int r1, int r2, int N, string s) {
   // Write your code here
   float comp= float(r1)/float(r2);
   int prime[100000]={0};

   prime[1]=0;
   for(int i=2;i<=N;i++){
       int p=Prime_check(i);
       prime[i]=p+prime[i-1];
   }
    int dp[100000]={0};
    if(s[0]!='*') dp[1]=0;  //base case
    else dp[1]=INT_MAX;
    
    for(int i=2;i<=N;i++){
        if(s[i-1]=='*'){
            dp[i]=INT_MAX;
            continue;
        }
        int op1,op2,op3;
        op1=op2=op3=INT_MAX; 
        int A=prime[i];
        float f=float(A)/float(i);
        if(f>=comp && A>2 && i-A>=0 && dp[i-A]!=INT_MAX){
            op3=dp[i-A]+1;
        }
        if(i-2>=0 && dp[i-2]!=INT_MAX) op2=dp[i-2]+1;
        if(i-1>=0 && dp[i-1]!=INT_MAX) op1=dp[i-1]+1;

        dp[i]=min(op1,min(op2,op3));
    }
    int ans=dp[N];
    if(ans==INT_MAX) return "No way!";
    return to_string(ans);
}

int main() {
    int t;cin>>t;
    while(t--){
        int r1,r2,n;
        cin>>r1>>r2>>n;
        string s;
        cin>>s;
        string s1=trap_sol(r1,r2,n,s);
        cout<<s1<<endl;
    }
    return 0;
}