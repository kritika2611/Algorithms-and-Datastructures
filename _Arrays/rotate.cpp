#include <bits/stdc++.h>

using namespace std;

int main()
{
    string original;
    int r;
    string new_str;
    cout<<"enter the string: ";
    getline(cin,original);
    int n=original.length();
    cout<<"enter the number of rotations: ";
    cin>>r;
    //rotate
    int i=n-r;
    for(;i<n;i++){
        new_str.push_back(original[i]);
    }
    if(i==n){
        for(int j=0; j<n-r; j++){
            new_str.push_back(original[j]);
        }
    }
    cout<<new_str;

    return 0;
}
