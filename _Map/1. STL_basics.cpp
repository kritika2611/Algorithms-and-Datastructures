#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    map <string,int> m;   //interal BST  (keys)
    //insertion
    m.insert(make_pair("Maggi",20));        
    m.insert(make_pair("Rajma Chawal",50));
    m["Pepsi"]=25;
    m["Burger"]=60;
    m["Pizza"]=100;

    //iteration
    for(auto it=m.begin();it!=m.end();it++) cout<<it->first<<" "<<it->second<<endl;

    cout<<endl;
    for(auto p:m) cout<<p.first<<" "<<p.second<<endl; cout<<endl;

    //Query
    map<string,int>::iterator it=m.find("Pepsi");
    if(it!=m.end()) cout<<"Pepsi is present "<<m["Pepsi"]<<endl;
    else cout<<"Pepsi not present"<<endl;

    //deletion
    m.erase("Pepsi");
    if(m.count("Pepsi")) cout<<"Pepsi is present "<<m["Pepsi"]<<endl;
    else cout<<"Pepsi not present"<<endl;

    return 0;
}
