/***********************************  Painter's partition  *******************************************************
Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards i.e. if the 
length of a particular board is 5, it will take 5 units of time to paint the board. Compute the minimum amount of 
time to paint all the boards.

Note that:
Every painter can paint only contiguous segments of boards.
A board can only be painted by 1 painter at maximum.
Input Format
First line contains K which is the number of painters. Second line contains N which indicates the number of boards. 
Third line contains N space separated integers representing the length of each board.

Constraints
1 <= K <= 10
1 <= N <= 10
1<= Length of each Board <= 10^8

Output Format
Output the minimum time required to paint the board.

Sample Input
2
2
1 10
Sample Output
10
***************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool ispossible(int p,int n,int *board,int time){
	int l=0;
	for(int i=0;i<p;i++){
		int curr_time=board[l];
		while(l<n){
			if(curr_time<=time){
				l++;
				curr_time+=board[l];
			}
			else
				break;
		}
	}
	if(l==n)
		return true;
	else
		return false;
}

int main(){
	int p,n;
	cin>>p>>n;

	int sum_=0;
	int max=INT_MIN;
	int *boards=new int[n];
	for(int i=0;i<n;i++){
		cin>>boards[i];
		sum_+=boards[i];
		max=(boards[i]>max)?boards[i]:max;
	}

	//binary search
	int s=max, e=sum_, ans=-1;
	while(s<=e){
		int mid=(s+e)/2;
		bool possible=ispossible(p,n,boards,mid);
		if(possible){
			e=mid-1;
			if(ans==-1 || mid<ans)
				ans=mid;
		}
		else
			s=mid+1;
	}
	cout<<ans;

	return 0;
}