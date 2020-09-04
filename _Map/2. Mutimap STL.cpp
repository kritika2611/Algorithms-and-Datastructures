/************************************************************************************************************************************************
INPUT:  10
        a apple
        v vendetta
        c catherine
        h harry
        b banana
        c cheese
        a anne
        c cat
        b balloon
        v voldemort
**********************************************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

typedef multimap <char,string>::iterator itr;

int main() {
    multimap <char,string> m;
    int n; cin>>n;
    while(n--){
        char a; string str;
        cin>>a>>str;
        m.insert(make_pair(a,str));   //insertion
    }

    //deleting specific value==cat
    itr i1=m.lower_bound('c');    // .lower_bound(key)
    itr i2=m.upper_bound('c');    // .upper_bound(key)
    for(itr i=i1;i!=i2;i++){
        if(i->second=="cat"){
            m.erase(i);            // .erase(address)
            break;
        }
    }


    //deleting all the values of a key
    m.erase('b');          // .erase(key)

    for(auto p:m) cout<<p.first<<" -> "<<p.second<<endl;
    cout<<endl;
    //query
    itr it=m.find('a');     // .find(key)
    if(it!=m.end()) cout<<"Present "<<it->second<<endl;

    // count
    cout<<m.count('c');

    return 0;
}
