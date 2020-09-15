#include <bits/stdc++.h>

using namespace std;
int main() {
    char s[1000];
    cin.getline(s,1000);

    char *sptr=strtok(s," ");
    while(sptr!=NULL){
        cout<<sptr<<endl;
        sptr=strtok(NULL," ");
    }
    cout<<endl;

    //using strings
    string s1;
    getline(cin,s1);
    char *ptr=strtok((char *)s1.c_str()," ");      // .c_str() converts string to char_array, then the char_array is typecasted as char *
    
    while(ptr!=NULL){
        string sub_s(ptr);
        cout<<sub_s<<":";
        ptr=strtok(NULL," ");
    }
}
