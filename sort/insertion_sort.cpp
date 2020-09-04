#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int n,int *arr){
    for(int i=1;i<n;i++){
        int e=arr[i];
        //placing e at the correct position
        for(int j=i-1;j>=0;j--){
            if(arr[j]<=e){
                arr[j+1]=e;
                break;
            }
        
            else if(arr[j]>e){
                arr[j+1]=arr[j];
                if(j==0)
                    arr[j]=e;
            }               
        }        
    }
}


/* ALTERNATE APPROACH
for(int i=1;i<n;i++){
    int e=arr[i];
    while(j>=0 and arr[j]>e){
        arr[j+1]=arr[j];
        j=j-1;
    }
    arr[j+1]=e;
}
*/


int main(){
    int n;
    cin>>n;
    
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    insertion_sort(n,arr);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}