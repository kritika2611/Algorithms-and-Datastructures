/*********************************************** SLIDING WINDOW *************************************************************************

Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Input
the number n denoting number of elements in the array then after a new line we have the numbers of the array and then k in a new line

n < 10^6
k < 10^5
1 <= k <= n

and each element of the array is between 0 and 10^6

(Edited: In fact, n <= 10^5)

Output
print the output array

Example
Input:
9
1 2 3 1 4 5 2 3 6
3

Output:
3 3 4 5 5 5 6
***********************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int arr[100000];
	int k;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>k;

	//deque
	deque <int> d;
	int i=0;
	for(;i<k;i++){
		while(!d.empty() && arr[d.back()]<=arr[i]){
			d.pop_back();
		}
		d.push_back(i);
	}

	for(;i<n;i++){
		cout<<arr[d.front()]<<" ";

		//remove all the elements not in the window
		while(!d.empty() && arr[d.front()]<=i-k){
			d.pop_front();
		}

		//remove all the prev elements in the window smaller than current element
		while(!d.empty() && arr[d.back()]<=arr[i]){
			d.pop_back();
		}

		//adding the current element
		d.push_back(i);
	}

	cout<<arr[d.front()];
	return 0;
}
