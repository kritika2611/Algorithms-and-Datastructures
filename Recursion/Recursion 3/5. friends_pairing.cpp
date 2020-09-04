/***************************************************  FRIENDS PAIRING *****************************************************************************
Given n friends. each of them can either go solo on the bike or go as a couple.
Find the number of ways they can go.

E.G- N=3
then output=4

**************************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int f(int n){
    //base case
    if(n==1 || n==0)
        return 1;
        
    //recursive case
    int x=f(n-1);
    int y=(n-1)*f(n-2);
    return x+y;
}

int main()
{
    int n;
    cin>>n;
    cout<<f(n);

    return 0;
}