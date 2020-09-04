/**********************************************************************************************************************
                                          ARRAYS-TARGET SUM TRIPLETS
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all triplets of numbers which sum to target.

Input Format:
First line contains input N. Next N lines contains the elements of array and N+1 line contains target number.

Constraints:
Length of Array should be between 1 and 1000.

Output Format
Print all the triplet present in the array.

Sample Input
9
5 7 9 1 2 4 6 8 3 
10
Sample Output
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5
********************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,target;
    cin>>n;
    int arr[1005];
    //input the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>target;
    
    //main code
    int l,r,sum_;
    //sorting the array
    sort(arr,arr+n);

    for(int i=0;i<n;i++){
        l=i+1;
        r=n-1;
        while(l<r){
            sum_=arr[i]+arr[l]+arr[r];
            if(sum_==target){
                cout<<arr[i]<<", "<<arr[l]<<" and "<<arr[r]<<endl;
                l++;
                r--;
            }
            else if(sum_<target)  l++;
            else if(sum_>target)  r--;
        }
    }

    return 0;
}