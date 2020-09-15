/************************************************************************************************************************************************
                                                            Run Length Encoding
Given an input string, write a function that returns the Run Length Encoded string for the input string.
For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6”.
************************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int n=s.length();

    char l=s[0];
    int li=0;
    for(int i=1;i<n;i++){
        if(s[i]==l) continue;
        else{
            int count=i-li;
            cout<<l<<count;
            li=i;
            l=s[i];
        }
    }
    int count=n-li;
    cout<<l<<count;
    return 0;
}
