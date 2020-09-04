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

int main()
{
   char s[]="3704";
   int n=strlen(s);
   
   int ans=str2int(s,n);
   cout<<ans;
   return 0;
}