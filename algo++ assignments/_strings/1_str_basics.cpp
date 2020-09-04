#include <iostream>
#include <string>      //STL library

using namespace std;

int main(){
	string s0;
	string s1("hello!");
	string s2(s1);          //or s2=s1;
	cout<<s2<<endl;

	char arr[]={'a','b','c','d','\0'};
	string s3(arr);
	cout<<s3<<endl;

	//empty function
	if(s0.empty()){
		cout<<"s0 is empty"<<endl;
	}

	//append
	s0.append("I love C++");
	cout<<s0<<endl;
	s0=s0+" and python";
	cout<<s0<<endl;

	//compare function
	string s4="kritika";
	string s5="divij";
	cout<<s5.compare(s5)<<endl;
	
	//find function
	string s="I want apple juice and apple";
	int idx=s.find("apple");
	cout<<idx<<endl;

	//remove a word
	string a="apple";
	int l=a.length();
	s.erase(idx,l+1);
	cout<<s<<endl;

	//iterate
	for(int i=0;i<s.length();i++)
		cout<<s[i]<<".";
	cout<<endl;

	for(auto c:s)
		cout<<c<<":";
	cout<<endl;

	for(auto i=s.begin();i<s.end();i++)
		cout<<(*i)<<"|";
	cout<<endl;


	return 0;
}