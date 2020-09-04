/*********************************************************************************************************************
                                        RAIN WATER HARVESTING
Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
Elevation Map

So the total units of water she can save is 5 units

Input Format:
First line contains an integer n. Second line contains n space separated integers representing the elevation map.
Output Format:
Print a single integer containing the maximum unit of waters she can save.

Sample Input
10
0 2 1 3 0 1 2 1 2 1
Sample Output
5
*********************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, maxr, maxl,ans=0;
	int arr[1000];

	//taking input
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	//main code
	for(int i=0; i<n; i++){
		maxl=int(*max_element(arr,arr+i+1));
		maxr=int(*max_element(arr+i,arr+n));
		ans+=min(maxl,maxr)-arr[i];
	}
	cout<<ans;
	return 0;
}