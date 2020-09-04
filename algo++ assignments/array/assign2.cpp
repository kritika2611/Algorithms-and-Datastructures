/************************************************************************************************************
                                  ARRAYS-WAVE PRINT COLUMN WISE
Q Take as input a two-d array. Wave print it column-wise.

Input Format:
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints:
Both M and N are between 1 to 10.

Output Format
All M * N integers seperated by commas with 'END' wriiten in the end.
**************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>m>>n;
    int arr[15][15];
//taking input
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
//waveprint
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            if(j%2==0)
            cout<<arr[i][j]<<", ";
            else
            cout<<arr[m-1-i][j]<<", ";
        }
    }
    cout<<"END";
	return 0;
}