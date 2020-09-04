/**********************************************************************************************************************
                                              MAXIMUM LENGTH BIOTONIC SUBARRAY
You are provided n numbers of array. You need to find the maximum length of bitonic subarray. A subarray A[i … j] is 
biotonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] i.e 
subarray is first increasing and then decreasing or entirely increasing or decreasing.

Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n which is 
the size of array and next line contains n space separated integers.

Constraints:
1<=t<=100 1<=n<=1000000

Output Format
Print the maximum length.

Sample Input
2
6
12 4 78 90 45 23
4
40 30 20 10
Sample Output
5
4
*********************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int test,n;
	int *arr=NULL;

	cin>>test;

	for(int t=0;t<test;t++){
		cin>>n;
		arr=new int[n];
		//input to array
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		int *inc=new int[n];
		int *dec=new int[n];
		int c1=1,c2=1;

		inc[0]=1;
		for(int i=1;i<n;i++){
			if(arr[i]>=arr[i-1]){
				c1+=1;
				inc[i]=c1;
			}
			else{
				c1=1;
				inc[i]=c1;
			}
		}

		dec[n-1]=1;
		for(int i=n-2;i>=0;i--){
			if(arr[i]>=arr[i+1]){
				c2+=1;
				dec[i]=c2;
			}
			else{
				c2=1;
				dec[i]=c2;
			}
		}

		int val,max_val;
		for(int i=0;i<n;i++){
			val=inc[i]+dec[i]-1;

			if(i==0)
				max_val=val;
			else
				max_val=(val>max_val)?val:max_val;
		}
		cout<<max_val<<endl;
		
		delete [] inc;
		delete [] dec;
		
	}

	delete [] arr;
	return 0;
}