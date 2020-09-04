#include <iostream>
#include <set>
using namespace std;

typedef multiset <int>::iterator I;

int main() {
    int arr[]={3,1,4,2,0,3,2,4,1,1,8,3,11};
    int n=sizeof(arr)/sizeof(int);
    multiset <int> m(arr,arr+n);     //initialisation

    m.insert(11);      // .insert()

    for(int e:m) cout<<e<<" ";

    cout<<endl<<"Count of 1= "<<m.count(1);           // .count()
    cout<<endl<<"Count of 2= "<<m.count(2);
    cout<<endl;

    m.erase(4);             // .erase() -- erases all occurance of that value

    I it=m.find(2);    // .find() -- address of the first element
    cout<<*it<<endl;

    pair<I,I> range=m.equal_range(1);          // for all occurance of a value-- returns a pair of addresses
    for(auto it=range.first; it!=range.second;it++) cout<<(*it)<<"-";
    cout<<endl;

    for(auto i=m.lower_bound(1);i!=m.upper_bound(8);i++) cout<<*i<<"-";   // .lower_bound() and .upper_bound()
    
    return 0;
}
