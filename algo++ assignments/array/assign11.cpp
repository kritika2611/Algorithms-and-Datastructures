/*****************************************************************************************************************
 										FORM BIGGEST NUMBER

You are provided an array of numbers. You need to arrange them in a way that yields the largest value.

Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n which 
is the size of array A[] and next line contains n space separated integers A[i] .

Constraints:
1<=t<=100 1<=m<=100 1<=A[i]<=10^5

Output Format
Print the largest value.

Sample Input
1
4
54 546 548 60
Sample Output
6054854654
***************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool compare(string str1,string str2){
	string str12=str1+str2;
	string str21=str2+str1;
	bool l=(str12.compare(str21))<0?0:1;
	return l;
}

int main(){
	int test,n;
	string arr[1000];
	cin>>test;
	for(int t=0;t<test;t++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n,compare);

		for(int i=0;i<n;i++){
			cout<<arr[i];
		}
		cout<<endl;
	}
	return 0;
}