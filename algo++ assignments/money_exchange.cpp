#include <bits/stdc++.h>

using namespace std;

int main(){
	//money exchange
	int coins[]={1,2,5,10,20,50,100,200,500,2000};
	int change;
	cin>>change;
	
	int n=sizeof(coins)/sizeof(coins[0]);
	//find the element less than or equal to money

	while(change>0){
		for(int i=n-1;i>=0;i--){
			if(coins[i]<=change){
				cout<<coins[i]<<" ";
				change-=coins[i];
				break;
			}
		}
	}
	return 0;
}