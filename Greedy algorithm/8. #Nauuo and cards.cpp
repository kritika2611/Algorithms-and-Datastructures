/****************************************************************************************************************************************
A. Nauuo and Cards

One day she was playing cards but found that the cards were mixed with some empty ones.
There are n cards numbered from 1 to n, and they were mixed with another n empty cards. She piled up the 2n cards and drew n of them. 
The n cards in Nauuo's hands are given. The remaining n cards in the pile are also given in the order from top to bottom.

In one operation she can choose a card in her hands and play it — put it at the bottom of the pile, then draw the top card from the pile.
Nauuo wants to make the n numbered cards piled up in increasing order (the i-th card in the pile from top to bottom is the card i) as quickly 
as possible. Can you tell her the minimum number of operations?

Input
The first line contains a single integer n (1≤n≤2⋅105) — the number of numbered cards.

The second line contains n integers a1,a2,…,an (0≤ai≤n) — the initial cards in Nauuo's hands. 0 represents an empty card.

The third line contains n integers b1,b2,…,bn (0≤bi≤n) — the initial cards in the pile, given in order from top to bottom. 0 represents an empty card.

It is guaranteed that each number from 1 to n appears exactly once, either in a1..n or b1..n.

Output
The output contains a single integer — the minimum number of operations to make the n numbered cards piled up in increasing order.

Examples
inputCopy
3
0 2 0
3 0 1
outputCopy
2
inputCopy
3
0 2 0
1 0 3
outputCopy
4
inputCopy
11
0 0 0 5 0 0 0 4 0 0 11
9 2 6 0 8 1 7 0 3 0 10
outputCopy
18
****************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool check_last_order(int n,int *hand,int *pile){
    int l=pile[n-1];
    if(l==0) return false;

    int i=n-1;
    while(i>=0 && l!=1){
        if(pile[i]==l){
            i--;
            l--;
            continue;
        }
        else return false;
    }

    if(pile[i]==1){
        if(pile[n-1]==n) return true;

        //check
        int ele=pile[n-1];
        for(int i=0;i<n;i++){
            if(pile[i]>ele && pile[i]<=n){
                if(i>=pile[i]-ele-1) return false;
            }
        }
        return true;
    }
    return false;
}

bool If_possible(int mid,int n,int *hand,int *pile){
    for(int i=mid;i<n;i++){
        if(1<=pile[i] && pile[i]<=n-mid+1){
            if(i>=pile[i]+mid-1) return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin>>n;
    int *hand=new int[n];
    int *pile=new int[n];
    for(int i=0;i<n;i++) cin>>hand[i];
    for(int i=0;i<n;i++) cin>>pile[i];

    //CHECK FOR ORDERED SEQUENCE

    bool order=check_last_order(n,hand,pile);
    if(order==true){
        int ans=n-pile[n-1];
        cout<<ans<<endl;
    }

    else{
        //binary search
        int s=0; int e=n;
        int x=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(If_possible(mid,n,hand,pile)){
                e=mid-1;
                if(x==-1 || x>mid) x=mid;
            }
            else s=mid+1;
        }
        int ans=x+n;
        cout<<ans<<endl;
    }

    return 0;
}
