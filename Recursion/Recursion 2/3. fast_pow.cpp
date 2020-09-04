#include <bits/stdc++.h>

using namespace std;

int fast_pow(int a,int n){
	//base case	
	if(n==0){
		return 1;
	}
	//recusrsive case
	int s=fast_pow(a,n/2);
	s=s*s;
	if(n&1){              //when n is odd
		return a*s;
	}
	return s;  //when n is even
}

int main(){
	int a,n;
	cin>>a>>n;
	cout<<fast_pow(a,n);

	return 0;
}

/* The time taken by this algorithm is log N */