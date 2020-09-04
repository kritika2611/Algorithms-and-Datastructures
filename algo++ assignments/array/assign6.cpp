/***********************************************************************************************************************
                                               MAXIMUM SUBARRAY SUM
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous 
subarray of numbers which has the largest sum. For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then 
the maximum subarray sum is 7.

Input Format:
The first line consists of number of test cases T. Each test case consists of N followed by N integers.
Constraints:
1 <= N <= 100000
Output Format
The maximum subarray sum

Sample Input
2
4
1 2 3 4
3
-10 5 10
Sample Output
10
15
**********************************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n,arr[100000];
    cin>>t;

    for(int i=0;i<t;i++){
        //taking input
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        
        //main code
        int ps=0,max_sum=0;
        for(int j=0;j<n;j++){
            ps+=arr[j];
            if(ps<0)
                ps=0;
            else if(ps>max_sum)
                max_sum=ps;

        }
    cout<<max_sum<<endl;
    }
    return 0;
 }

