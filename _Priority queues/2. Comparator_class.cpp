#include <bits/stdc++.h>
using namespace std;

class person{
public:
    string name;
    int marks;

    person(){

    }
    person(string s,int i){
        this->name=s;
        this->marks=i;
    }

};

class comp{
public:
    bool operator()(person a,person b){
        return a.marks<b.marks;
    }
};

int main() {
    priority_queue <person, vector<person>, comp> pq;
    int n; cin>>n;
    while(n--){
        string name;
        int marks;
        cin>>name>>marks;
        person p(name,marks);
        pq.push(p);
    }

    int k=4;
    while(k--){
        person p1=pq.top();
        cout<<p1.name<<endl;
        pq.pop();
    }
    return 0;
}
