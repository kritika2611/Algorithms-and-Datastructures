#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int solve_equation(char str[]){
	char *token;
	int ans;
	bool plus_flag=false,equal_flag=false;
	int X_idx=-1;
	vector<string> v;
	
	token=strtok(str,"+=");
	while(token!=NULL){
		v.push_back(token);
		token=strtok(NULL,"+=");        //tokens are saved in v
	}
	
	for(int i=0; i<v.size();i++){
		if (v[i]=="X"){
			X_idx=i;
		}
	}
	cout<<X_idx<<endl;
	
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='+'){
			plus_flag=true;
			cout<<plus_flag<<endl;
		}
		else if (str[i]=='='){
			equal_flag=true;
			cout<<equal_flag<<endl;
		}
		else
			continue;
	}
	cout<<plus_flag<<" "<<equal_flag<<endl;
	/*if(X_idx==0){

	}*/


	return 0;

}

int main(){
	char str[1000];
	cin.getline(str,1000);
	int X=solve_equation(str);
	return 0;

}