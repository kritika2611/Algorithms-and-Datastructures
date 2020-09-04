# include <bits/stdc++.h>

using namespace std;

char * Mystrtok(char str[],char delim){
	static char * state=NULL;
	if (str!=NULL){
		state=str;
	}
	char *output;   //plus 1 to store the '\0'
	output=new char [strlen(state)+1];
	if (state==NULL){
		return NULL;
	}

	int i;
	for(i=0;state[i]!='\0';i++){
		if (state[i]!=delim){
			output[i]=state[i];
		}
		else {
			output[i]='\0';
			state=str+i+1;
			return output;
		}
	}
	
	output[i]='\0';
	state=NULL;
	return output;

}

int main(){
	char str[150];
	char delim=' ';
	char * ptr;
	cout<<"enter the string: ";
	cin.getline(str,150);
	ptr=Mystrtok(str,delim);
	cout<<ptr<<endl;

	ptr=Mystrtok(NULL,delim);
	cout<<ptr<<endl;

	ptr=Mystrtok(NULL,delim);
	cout<<ptr<<endl;



	
	/*while(ptr!=NULL){
		cout<<ptr<<endl;
		ptr=Mystrtok(NULL,delim);
	}*/
	
	return 0;
}