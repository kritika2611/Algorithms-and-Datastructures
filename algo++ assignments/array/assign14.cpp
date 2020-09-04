#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mul=18;
    vector <int> arr={7,6,5,8};
    int n=arr.size();
    int carry[100]={0};
    carry[0]=0;
    
    for(int i=0;i<n;i++){
        int ans=arr[i]*mul+carry[i];
        arr[i]=ans%10;
        carry[i+1]=ans/10;
    }
    
    if(carry[n]!=0){
        int k=carry[n];
        do{
        arr.push_back(k%10);
        k=k/10;
        }while(k!=0);
    }
    
    for(int i=arr.size()-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    return 0;
}
