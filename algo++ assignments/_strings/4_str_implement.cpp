#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string get_keystring(string s,int key){
	char *sptr=strtok((char *)s.c_str()," ");
	int i=1;

	while(i!=key){
		i++;
		sptr=strtok(NULL," ");
	}
	return (string)sptr;

}

int to_int(string s){
	int num=0;
	int p=1;
	for(int i=s.length()-1;i>=0;i--){
		int d=s[i]-'0';
		num+=p*d;
		p=p*10;
	}
	return num;
}


bool n_comp(pair<string,string> p1,pair<string,string> p2){
	string key1,key2;
	key1=p1.second;
	key2=p2.second;
	return to_int(key1)<to_int(key2);
}

bool l_comp(pair<string,string> p1,pair<string,string> p2){
	string key1,key2;
	key1=p1.second;
	key2=p2.second;
	return key1<key2;
}

int main(){
	int n;
	cin>>n;
	cin.get();

	string arr[100];
	for(int i=0;i<n;i++)
		getline(cin,arr[i]);

	int key;
	string reverse,order;
	cin>>key;
	cin>>reverse;
	cin>>order;

	pair<string,string> p[100];
	for(int i=0;i<n;i++){
		p[i].first=arr[i];
		p[i].second=get_keystring(arr[i],key);
	}

	//sorting
	if(order=="n"){
		sort(p,p+n,n_comp);
	}
	else
		sort(p,p+n,l_comp);

	//reverse
	if(reverse=="true"){
		for(int i=0;i<n/2;i++){
			swap(p[i],p[n-1-i]);
		}
	}

	//print arr
	for(int i=0;i<n;i++){
		cout<<p[i].first<<endl;
	}

	return 0;
}