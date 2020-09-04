#include <bits/stdc++.h>

using namespace std;

bool check_paranthesis(string s){
    stack <char> st;
    
    for(auto e:s){
        if(e=='('){
            st.push(e);
        }
        else if(e==')'){
            if(st.empty())
                return false;
                
            else
                st.pop();
        }
    }
    
    if(st.empty()){
        return true;
    }
    return false;
}

int main()
{
    string s="((a+b)*(f+h))";
    //getline(cin,s);
    
    if(check_paranthesis(s)){
        cout<<"The brackets are balanced"<<endl;
    }
    else{
        cout<<"Brackets are not balanced";
    }
    return 0;
}
