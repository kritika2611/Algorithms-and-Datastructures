#include <iostream>
#include <list>

using namespace std;

int main(){
	//creating a list
	list <int> l;

	//intialising
	list <int>l1{1,2,3,4};
	list <string> l2={"apple","pineapple","guava","banana"};

	//printing
	for(auto s:l2){
		cout<<s<<" -> ";
	}
	cout<<endl;

	//front and back methods
	l2.pop_front();
	l2.push_front("kiwi");
	l2.pop_back();
	l2.push_back("maggi");

	//printing using iterators
	for(auto it=l2.begin();it!=l2.end();it++){
		cout<<*it<<" -> ";
	}
	cout<<endl;

	//sorting and reverse
	l2.sort();
	for(auto s:l2){
		cout<<s<<" -> ";
	}
	cout<<endl;

	l2.reverse();
	for(auto s:l2){
		cout<<s<<" -> ";
	}
	cout<<endl;

	l2.push_back("orange");
	l2.push_back("banana");
	l2.push_back("grapes");
	l2.push_front("kiwi");
	for(auto s:l2){
		cout<<s<<" -> ";
	}
	cout<<endl;

	//remove by value
	l2.remove("kiwi");
	for(auto s:l2){
		cout<<s<<" -> ";
	}
	cout<<endl;

	//erase by address
	auto it=l2.begin();
	it++;
	it++;
	l2.erase(it);
	for(auto s:l2){
		cout<<s<<" -> ";
	}
	cout<<endl;

	//insert by address
	auto i=l2.begin();
	i++;
	l2.insert(i,"apple");
	for(auto s:l2){
		cout<<s<<" -> ";
	}
	cout<<endl;


	return 0;
}