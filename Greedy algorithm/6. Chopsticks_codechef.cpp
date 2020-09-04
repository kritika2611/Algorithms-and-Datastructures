/*****************************************************************************************************************************************
												CHOPSTICKS
Actually, the two sticks in a pair of chopsticks need not be of the same length. A pair of sticks can be used to eat as long as the 
difference in their length is at most D. The Chef has N sticks in which the ith stick is L[i] units long. A stick can't be part of more 
than one pair of chopsticks. Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks.

Input
The first line contains two space-separated integers N and D. The next N lines contain one integer each, the ith line giving the value of 
L[i].

Output
Output a single line containing the maximum number of pairs of chopsticks the Chef can form.

Constraints
1 ≤ N ≤ 100,000 (10^5 )
0 ≤ D ≤ 1,000,000,000 (10^9 )
1 ≤ L[i] ≤ 1,000,000,000 (10^9 ) for all integers i from 1 to N
Example
Input:

5 2
1
3
3
9
4

Output:
2
****************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,d;
	cin>>n>>d;
	int *arr=new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	sort(arr,arr+n);
	
	int ans=0;
	int i=0;
	while(i<n-1){
		if(arr[i+1]-arr[i]<=d){
			ans+=1;
			i+=2;
		}
		else i+=1;
	}
	cout<<ans;
	return 0;
}