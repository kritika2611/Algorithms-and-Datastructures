#include <bits/stdc++.h>

using namespace std;

int main()
{
    char arr[1000];
    cin.getline(arr,1000);
    int n=strlen(arr);
    bool flag=true;
    for(int i=0;i<n/2;i++){
    	if(arr[i]!=arr[n-1-i]){
    		flag=false;
    		break;
    	}
    }
    if(flag)
    	cout<<"it is palindrome"<<endl;
    else
    	cout<<"not a palindome";
    
    return 0;
}
