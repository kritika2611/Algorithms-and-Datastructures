#include <bits/stdc++.h>

using namespace std;

int total_ways(int n,int k){
	//base case
	if(n==0 or n==1)
		return 1;

	//recursive case
	if(n>=k){
		int ways=0;
		for(int i=1;i<=k;i++)
			ways+=total_ways(n-i,k);

		return ways;
	}

	int ways=0;
	for(int i=1;i<=n;i++)
		ways+=total_ways(n-i,k);

	return ways;
}



int main(){
	int n,k;
	cin>>n>>k;
	cout<<total_ways(n,k);

	return 0;
}

