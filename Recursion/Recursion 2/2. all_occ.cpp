#include <bits/stdc++.h>

using namespace std;

int store_all_occ(int *arr,int n, int i,int key, int *out,int j){
    //base case
    if(i==n)
        return j;
    
    if(arr[i]==key){
        out[j]=i;
        j++;
    }
    return store_all_occ(arr,n,i+1,key,out,j);
}

void all_occ(int *arr,int n,int i,int key){
    //base case
    if(i==n)
        return;
    
    //recursive case
    if(arr[i]==key){
        cout<<i<<" ";
    }
    all_occ(arr,n,i+1,key);
}


int main()
{   
    int n,key;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    int *out=new int[100];
        
    cin>>key;
    all_occ(arr,n,0,key);
    cout<<endl;
    
    int occ=store_all_occ(arr,n,0,key,out,0);
    for(int i=0;i<occ;i++){
        cout<<out[i]<<" ";
    }
    return 0;
}
