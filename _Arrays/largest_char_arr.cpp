#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	cin.get();

	char l_str[1000]="";
	char c_str[1000];
	for(int i=0;i<n;i++){
		cin.getline(c_str,1000);
		if(strlen(l_str)<strlen(c_str)){
			int j=0;
			for(;j<strlen(c_str);j++){
				l_str[j]=c_str[j];
			}
			l_str[j]='\0';
		}
	}

	cout<<endl<<l_str<<" "<<strlen(l_str);


	return 0;
}