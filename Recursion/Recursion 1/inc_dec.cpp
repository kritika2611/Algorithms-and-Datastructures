#include <bits/stdc++.h>

using namespace std;

void inc_order(int n){
   //base case
   if(n==1){
       cout<<n<<" ";
       return;
   }
  inc_order(n-1);
  cout<<n<<" ";
}

void dec_order(int n){
    if(n==1){
        cout<<n<<endl;
        return;
    }
    cout<<n<<" ";
    dec_order(n-1);
}

int main()
{
    int n;
    cin>>n;
    dec_order(n);
    inc_order(n);

    return 0;
}
