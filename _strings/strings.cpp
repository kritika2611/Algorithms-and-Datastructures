#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	int numguessed;
	string name, fullname;
	string last_name;
	string xyz;

	cout<<"What is your first name: ";
	getline(cin,name);                // inputs a string from the keyboard
	name.append(" ");         //appends a new string at the end of the previous string
	cout<<"Enter your last name: ";
	getline(cin,last_name);
	fullname=name+last_name;       //concatenates two strings
	cout<<"hello "<<fullname<<" !"<<endl;           
	cout<<"comparing your name:"<<name.compare(last_name)<<endl;
	xyz=fullname.insert(name.size(),"Anurag ");
	cout<<xyz<<endl;

	do
	{
		cout<<"Guess a number between 1 to 10 :" ;
		getline(cin,xyz);
		numguessed=stoi(xyz);      //stoi - converts string to integer
	}while(numguessed!=5);
	cout<<"You guessed the correct number";

	return 0;
}