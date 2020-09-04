/***************************************      UNIQUE 3    ********************************************************
Give an array with every element repeating thrice except one.
find that element.      3N+1
**************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	int *arr=new int[n];

	int bit_sum[64]={0};       //fixed size array is considered as constant space O(1)

	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		int j=0;
		while(num>0){
			int bit=num&1;
			bit_sum[j]+=bit;
			j++;
			num=num>>1;
		}
	}

	int ans=0,p=1;
	for(int i=0;i<64;i++){
		bit_sum[i]=bit_sum[i]%3;
		ans+=bit_sum[i]*p;
		p=p<<1;
	}
	cout<<ans;

	return 0;
}