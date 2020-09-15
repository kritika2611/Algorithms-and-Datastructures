#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1="105";
    string s2="5637";
    cout<<"string to numbers: "<<endl;
    int n1=stoi(s1);    
    int n2=stoi(s2);     // stoi(string) ->takes string as input and convert it into number
    cout<<n1<<" "<<n2<<endl;

    char a1[1000]="357";
    char a2[1000]="435267";
    cout<<endl<<"Character array into number: "<<endl;
    int num1=atoi(a1);
    int num2=atoi(a2);
    cout<<num1<<" "<<num2<<endl;
    return 0;
}
