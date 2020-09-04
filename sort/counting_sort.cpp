/**********************************************************************************************************************************
Counting sort sorts elements in a given range.
time= O(n+k)
Space=O(n+k)

INPUT:
num= 10
arr= 5 8 6 4 9 2 2 3 8 5
range= 2 10

OUTPUT: 2 2 3 4 5 5 6 8 8 9
********************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void counting_sort(int n,int low_lim,int up_lim,int *arr){
    int *out=new int[n];

    //k=total elements in range--> up_lim-low_lim+1
    int k=up_lim-low_lim+1;
    int count[k]={0};
    for(int i=0;i<n;i++){
        int idx=arr[i]-low_lim;
        count[idx]+=1;
    }

    for(int i=1;i<n;i++) count[i]+=count[i-1];    //last position of element
    for(int i=0;i<n;i++){
        int c=count[arr[i]-low_lim];
        if(c<=0) continue;
        out[c-1]=arr[i];
        count[arr[i]-low_lim]-=1;
    }

    for(int i=0;i<n;i++) arr[i]=out[i];
}
int main() {
    int n,low_lim,up_lim;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>low_lim>>up_lim;

    counting_sort(n,low_lim,up_lim,arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    delete [] arr;
    return 0;
}
