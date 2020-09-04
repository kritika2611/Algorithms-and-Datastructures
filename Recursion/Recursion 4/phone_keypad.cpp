#include <bits/stdc++.h>

using namespace std;

char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void get_strings(char *in,int i,char *out, int j){
    //BASE case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return ; 
    }
        
    //recursive case
    int digit=in[i]-'0';
    int k=0;
    while(keypad[digit][k]!='\0'){
        out[j]=keypad[digit][k];
        k++;
        get_strings(in,i+1,out,j+1);
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

