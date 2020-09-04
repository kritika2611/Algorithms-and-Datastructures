#include <bits/stdc++.h>

using namespace std;

bool compare(int a,int b){
    return a>b;
}

void bubble_sort(int n,int *arr, bool(&comp)(int a,int b)){
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<=n-i-1;j++){
            if(comp(arr[j+1],arr[j]))
                swap(arr[j+1],arr[j]);
        }
        
    }
}


int main()
{
    int n;
    cin>>n;
    
    int *arr=new int[n];
    for(int i=0;i<5;i++)
        cin>>arr[i];
        
    bubble_sort(n,arr,compare);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    return 0;
}
