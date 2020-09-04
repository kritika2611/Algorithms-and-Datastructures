#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[]={1,2,5,8,8,8,8,8,10,12,15,20};
    int n=sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    
    //binary search
    int s=0;
    int e=n-1;
    int idx=-1;
    
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            e=mid-1;
            if(idx==-1 || mid<idx)
                idx=mid;
        }
        else if(arr[mid]<key)
            s=mid+1;
        else
            e=mid-1;
    }
    
    cout<<idx;

    return 0;
}
