/**********************************************************************************************************************
                                                    MAXIMUM CIRCULAR SUM
You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum 
sum of consecutive number.

Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the 
size of numbers and next line contains n space separated integers.

Constraints:
1<=t<=100 1<=n<=1000

Output Format
Print the maximum sum.

Sample Input
1
7
8 -8 9 -9 10 -11 12
Sample Output
22
********************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int test,n,arr[1005]={0};
	int max_sum,ps;
	cin>>test;
	
	for(int t=0;t<test;t++){
		max_sum=0;

		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		for(int st=0;st<n;st++){
			ps=0;
			int i=st;
			while(i!=st-1){
				ps+=arr[i];
				ps=(ps<0)?0:ps;
				max_sum=(max_sum>ps)?max_sum:ps;

				if (i==n-1 && st==0)
					i=-1;
				else if(i==n-1)
					i=0;
				else
					i++;
			}
		}
		cout<<max_sum<<endl;
	}

	return 0;
}
