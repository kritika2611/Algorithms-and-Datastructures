#include <bits/stdc++.h>

using namespace std;

int first_occ(int *arr, int n, int key){
    //base case
    if(n==0)
        return -1;
    else if(*arr==key)
        return 0;
        
    //recursive case
    int check=first_occ(arr+1,n-1,key);
    int ans=(check==-1)?-1:(1+check);
    return ans;
    
}

int first_occ2(int *arr, int n, int i,int key){
    if(i==n)
        return -1;
        
    else if(arr[i]==key)
        return i;
    
    return first_occ2(arr,n,i+1,key);   
}

int last_occ(int *arr,int n,int key){
    //base case
    if(n==0)
        return -1;
    
    //recursive case    
    int i=last_occ(arr+1,n-1,key);
    if(i==-1 && *arr==key)
        return 0;
    else if(i==-1 && *arr!=key)
        return -1;
    else if(i!=-1)
        return i+1;
}


int main()
{   
    int n,key;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    cin>>key;
    cout<<first_occ(arr,n,key)<<endl;
    cout<<first_occ2(arr,n,0,key)<<endl;
    cout<<last_occ(arr,n,key);

    return 0;
}
