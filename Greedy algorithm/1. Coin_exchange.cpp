#include <bits/stdc++.h>

using namespace std;

int locally_optimal(int n,int money,int *coins){
    int s=0;
    int e=n-1;
    int ans=-1;

    while(s<=e){
        int mid=(s+e)/2;
        if(coins[mid]==money) return mid;
        else if(coins[mid]<money){
            s=mid+1;   
            if(ans==-1 || ans<coins[mid]) ans=mid;
        }
        else e=mid-1;
    }
    return ans;
}

int indian_coin_exchange(int n,int change,int *coins){
    //locally optimal solution

    //int idx=upper_bound(coins,coins+n,change)-coins-1; OR
    int idx=locally_optimal(n,change,coins);
    
    int ans=0;
    while(change!=0){
        cout<<coins[idx]<<" + ";
        change=change-coins[idx];
        idx=locally_optimal(n,change,coins);
        ans+=1;
    }
    return ans;
}
int main()
{
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int n=sizeof(coins)/sizeof(int);
    int change;
    cin>>change;

    int ans=indian_coin_exchange(n,change,coins);
    cout<<endl<<ans;

    return 0;
}
