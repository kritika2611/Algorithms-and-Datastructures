#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[]={11,5,2,1,5,3,3,6,9};
    set <int> s1;
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++) s1.insert(arr[i]);    // .insert()

    s1.erase(5);        // .erase() ->takes both address and value as argument
    
    auto it=s1.find(6);   // .find() ->returns the address of the element
    s1.erase(it);

    for(auto e:s1) cout<<e<<" ";
    cout<<endl;

    set <pair<int,int>> s2;
    s2.insert(make_pair(10,6));
    s2.insert(make_pair(70,8));
    s2.insert(make_pair(6,6));
    s2.insert(make_pair(10,8));
    s2.insert(make_pair(5,4));
    s2.insert(make_pair(6,8));
    s2.insert(make_pair(10,4));

    
    for(set <pair<int,int>> :: iterator it=s2.begin(); it!=s2.end(); it++){             // .begin() && .end()
        cout<<it->first<<" "<<it->second<<endl;
    }

    auto it1=s2.upper_bound(make_pair(10,4));                  // .upper_bound()
    auto it2=s2.lower_bound(make_pair(10,4));                 // .lower_bound()

    cout<<"Upper bound "<<it1->first<<","<<it1->second<<endl;
    cout<<"Lower bound "<<it2->first<<","<<it2->second<<endl;

    auto it3=s2.upper_bound(make_pair(6,INT_MAX));               //TO FIND UPPER BOUND wrt one element
    auto it4=s2.lower_bound(make_pair(6,INT_MAX));
    cout<<"Upper Bound "<<it3->first<<","<<it3->second<<endl;
    cout<<"Lower Bound "<<it4->first<<","<<it4->second;
    return 0;
}
