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
	auto lb= upper_bound(coins,coins+n,change);
	int idx=lb-coins-1;
	cout<<coins[idx]<<" ";
	change-=coins[idx];
	}

	return 0;
}