#include <bits/stdc++.h>

using namespace std;

void get_strings(char *in,int i,char *out, int j){
    //base case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    
    //recursive case
     //taking one element
    int k=in[i]-'0';
    char ch='A'+k-1;
    out[j]=ch;
    get_strings(in,i+1,out,j+1);
    
    //taking two elements
    if(in[i+1]!='\0'){
        int k=in[i]-'0';
        int k_=in[i+1]-'0';
        int num=10*k+k_;
        
        if(num<=26){
            char ch='A'+num-1;
            out[j]=ch;
            get_strings(in,i+2,out,j+1);
        }
    }
    return;
}




int main()
{   
    char in[1000];
    cin.getline(in,1000);
    char out[1000];
    get_strings(in,0,out,0);
    
    return 0;
}
