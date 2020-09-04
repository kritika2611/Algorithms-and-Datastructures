/*******************************************AGGRCOW - Aggressive cows****************************************************************************

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN 
(0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from 
hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. 
What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
*************************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool feasible(int N, int *stalls, int C, int min_sep){
	int last_idx=0;
	C--;
	for(int i=1;i<N;i++){
		if(stalls[i]-stalls[last_idx]>=min_sep){
			last_idx=i;
			C--;
			if(C==0)
				return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int N,C;
		cin>>N>>C;

		int *stalls=new int[N];
		for(int i=0;i<N;i++)
			cin>>stalls[i];

		sort(stalls, stalls+N);

		//binary search
		// montonic search space   
		int s=0, e=stalls[N-1]-stalls[0];
		int ans=-1;
		while(s<=e){
			int mid=(s+e)/2;
			bool feas=feasible(N,stalls,C,mid);
			if(feas){
				s=mid+1;
				if(ans==-1 || mid>ans)
					ans=mid;
			}
			else
				e=mid-1;
		}

		cout<<ans<<endl;

	}
	return 0;
}