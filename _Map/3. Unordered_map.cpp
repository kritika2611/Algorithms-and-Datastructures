#include <bits/stdc++.h>
using namespace std;

typedef unordered_map <string,int>::iterator itr;

int main() {
    unordered_map <string,int> um;

    //insertion
    um.insert(make_pair("Maggi",20));        
    um.insert(make_pair("Rajma Chawal",50));
    um["Pepsi"]=25;
    um["Burger"]=60;
    um["Pizza"]=100;
    um["Apple"]=5;

    //iteration
    for(auto p:um) cout<<p.first<<" : "<<p.second<<endl;
    cout<<endl;

    //find
    if(um.count("Pepsi")) cout<<"Pepsi is present"<<endl;
    else cout<<"Pepsi not present"<<endl;

    //erase
    um.erase("Pepsi");

    //find
    if(um.find("Pepsi")!=um.end()) cout<<"Pepsi is present"<<endl;
    else cout<<"pepsi not present"<<endl;

    return 0;
}
