/*************************************************************************************************************************************************
count number of binary strings of length n, having no consecutive ones.
************************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int f(int n){
    //base case
    if(n==1)
        return 2;
    if(n==0)
        return 1;
        
    //recursive case
    return f(n-1)+f(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<f(n);

    return 0;
}
