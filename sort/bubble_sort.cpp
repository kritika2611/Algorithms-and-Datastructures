#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int n,int *arr){
    for(int i=1;i<n;i++){
        //swapping
        for(int j=0;j<=n-i-1;j++){
            if (arr[j+1]<arr[j])
                swap(arr[j],arr[j+1]);        
        }
    }
}

int main(){
    int n;
    cin>>n;
    
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    bubble_sort(n,arr);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}