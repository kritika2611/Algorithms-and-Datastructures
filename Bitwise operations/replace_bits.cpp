/****************************************** REPLACE BITS ********************************************************
You are given two 32 bits number,N and M, and two bit positions i and j.
Write a method to set all the bits in i and j in N equal to M.(M becomes a substring of N from i to j)

EXAMPLE:
Input=10000000000
i=2, j=6
M=10101

Output=100001010100
**************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int N,M,i,j;
	cin>>N>>M>>i>>j;

	//clear the bits from i to j
	int m1=(-1<<(j+1));
	int m2=(1<<i)-1;
	int m=m1|m2;
	N=N&m;
	//place m in cleared bits
	M=M<<i;
	N=N|M;
	cout<<N<<endl;
	return 0;
}