#include <iostream>
#include<cstring>

using namespace std;

void func(char s[]){
	int n=strlen(s);
	int i,j;
	if(n==0 || n==1)
		return;
	else{
		i=0;
		j=1;
		while(j<=n-1){
			if(s[i]==s[j])
				j++;
			else{
				i++;
				s[i]=s[j];
				j++;
			}
		}
	}
	s[i+1]='\0';
	cout<<s;
	cout<<endl<<strlen(s);

}


int main(){
	char arr[1000];
	cin>>arr;
	func(arr);

	return 0;
}