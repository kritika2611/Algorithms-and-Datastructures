#include <iostream>
#include "my_vector.h"

using namespace std;

int main(){
	myvector <char> v;

	v.push_back('a');
	cout<<"size: "<<v.size()<<"   capacity: "<<v.capacity()<<endl;

	v.push_back('k');
	cout<<"size: "<<v.size()<<"   capacity: "<<v.capacity()<<endl;

	v.push_back('n');
	cout<<"size: "<<v.size()<<"   capacity: "<<v.capacity()<<endl;

	v.push_back('r');
	cout<<"size: "<<v.size()<<"   capacity: "<<v.capacity()<<endl;

	v.push_back('p');
	v.pop_back();
	cout<<"size: "<<v.size()<<"   capacity: "<<v.capacity()<<endl;

	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;

	cout<<v.front()<<endl;
	cout<<v.back()<<endl;
	cout<<v.empty()<<endl;
	v.clear();
	cout<<v.empty()<<endl;

	return 0;
}