#include <bits/stdc++.h>

using namespace std;

int str2int(char *s, int n){
    //base case
    if(n==0)
        return 0;
        
    //recursive case
    int digit=*(s+n-1)-'0';
    int rec=str2int(s,n-1);
    
    return rec*10+digit;
    
    
}

int iterative_str2int(string s,int n){
    int num=s[0]-'0';
    for(int i=1;i<n;i++){
        int digit=s[i]-'0';
        num=num*10+digit;
    }
    return num;
}

int main()
{
   char s[]="3704";
   int n=strlen(s);
   
   int ans=str2int(s,n);
   cout<<ans<<endl;

   string s1(s);
   cout<<iterative_str2int(s1,n);
   return 0;
}