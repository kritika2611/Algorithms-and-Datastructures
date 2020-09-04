#include <bits/stdc++.h>

using namespace std;

int  func(int*arr,int n){
    int xor_=0;
    for(int i=0;i<n;i++){
        xor_=xor_^arr[i];
    }
    return xor_;
}
int main() {
    int n,m,k;
    cin>>n>>k>>m;
    int arr[n]={0};int i=0,j=0;
    while(i<=(m+k)){
        int ans;cin>>ans;
        if(i>=m){
            arr[j]=ans;j++;
        }
        i++;
    }
    cout<<j<<endl;
    cout<<func(arr,j);
}
