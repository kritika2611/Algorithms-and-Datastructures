#include <iostream>
#include <set>
using namespace std;

typedef multiset <int>::iterator I;

class comp{
public:
    bool operator()(pair<string,int> p1,pair<string,int> p2){
        return p1.second>p2.second;
    }
};

int main() {
    multiset <pair<string,int>,comp> m;
    pair <string,int> p1=make_pair("Binod",100);
    pair <string,int> p2=make_pair("Aakash",80);
    pair <string,int> p3=make_pair("Chetna",20);
    pair <string,int> p4=make_pair("Divij",120);

    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);

    for(auto p:m) cout<<p.first<<" , "<<p.second<<endl;
    
    return 0;
}
