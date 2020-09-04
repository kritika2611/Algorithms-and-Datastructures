

/*******using base 10 approach**************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    //base 10
    int ans=0,p=1;
    while(n>0){
        int l_bit=n&1;
        ans+=l_bit*p;
        p=p*10;
        n=n>>1;
    }
    cout<<ans;
    return 0;
}

