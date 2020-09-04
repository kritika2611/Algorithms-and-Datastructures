#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char *mystrtok(char *s,char del){
	static char *input=NULL;
	if(s!=NULL)
		input=s;

	char *output=new char[strlen(input)+1];

	if(input==NULL){          //after traversing throughot the arr
		output=NULL;
		return output;
	}
	
	
	int i=0;
	for(;input[i]!='\0';i++){
		if(input[i]!=del){
			output[i]=input[i];        //copying the arr till we find the delim
		}
		else{
			output[i]='\0';
			input=input+i+1;
			return output;
		}
	}
	output[i]='\0';
	input=NULL;
	return output;
}

int main(){
	char arr[1000];
	cin.getline(arr,1000);
	char *ptr=mystrtok(arr,'!');
	cout<<ptr<<endl;

	while(ptr!=NULL){
		ptr=mystrtok(NULL,'!');
		cout<<ptr<<endl;
	}
	return 0;
}