#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

void permute(string s,int i,set <string> &my_set){
    //base case
    if(s[i]=='\0'){
        my_set.insert(s);
        return;
    }

    //recursive case
    for(int j=i;s[j]!='\0';j++){
        swap(s[i],s[j]);
        permute(s,i+1,my_set);
        swap(s[i],s[j]);    //backtracking
    }
}

int main(){
    string s;
    getline(cin,s);
    set <string> my_set;
    permute(s,0,my_set);

    for(auto str:my_set)
        cout<<str<<" ";

    return 0;

}