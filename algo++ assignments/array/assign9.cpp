/*****************************************************************************************************************
                                      ARRAYS-SPIRAL PRINT ANTICLOCKWISE
Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

Input Format:
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints:
Both M and N are between 1 to 10.

Output Format:
All M * N integers separated by commas with 'END' written in the end(as shown in example).

Sample Input:
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44

Sample Output:
11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END
****************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void print_spiral(int m, int n, int arr[10][10]){
	int strow=0,endrow=m-1;
	int strcol=0,endcol=n-1;
	while (strow<endrow){
		for(int i=strow;i<=endrow;i++){
			cout<<arr[i][strcol]<<", ";
		}
		strcol++;
		for(int j=strcol;j<=endcol;j++){
			cout<<arr[endrow][j]<<", ";
		}
		endrow--;
		for(int i=endrow;i>=strow;i--){
			cout<<arr[i][endcol]<<", ";
		}
		endcol--;
		for(int j=endcol;j>=strcol;j--){
			cout<<arr[strow][j]<<", ";
		}
		strow++;
	}
	cout<<"END";
}

int main(){
	int m,n;
	cin>>m>>n;
	int arr[10][10];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	print_spiral(m,n,arr);
	return 0;
}