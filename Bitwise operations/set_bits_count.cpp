#include <bits/stdc++.h>

using namespace std;

//time complexity=O(log n)
int approach1(int n){
	int ans=0;         
	while(n>0){
		ans+=(n&1);
		n=n>>1;
	}
	return ans;
}

//time complexity = O(no. of set bits)
int approach2(int n){
	int ans=0;
	while(n!=0){
		n=n&(n-1);     //removes the last set bit
		ans++;
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	cout<<approach1(n)<<endl;
	cout<<approach2(n)<<endl;
	cout<<__builtin_popcount(n)<<endl;

	return 0;
}