#include <bits/stdc++.h>

using namespace std;

class my_stack{
private:
    int s[10]={0};
    int *ptr=s-1;
    
public:
    //constructor
    my_stack(){
        
    }
    
    bool IsFull(){
        return ptr==s+9;
    }
    
    bool IsEmpty(){
        return ptr==s-1;
    }
    
    void push(int data){
        if(this->IsFull()){
            cout<<"Stack overflow"<<endl;
            return;
        }
        ptr++;
        *ptr=data;
    }
    
    void pop(){
        if(this->IsEmpty()){
            cout<<"Stack underflow"<<endl;
            return;
        }
        *ptr=0;
        ptr--;
    }
    
    int top(){
        return *ptr;
    }
    
};

int main()
{
    my_stack st;
    st.pop();
    st.push(2);
    st.push(3);
    st.push(10);
    st.push(12);
    st.push(17);
    st.push(2);
    st.push(3);
    st.push(10);
    st.push(12);
    st.push(17);
    if(st.IsFull()){
        cout<<"stack is full"<<endl;
    }
    st.pop();
    st.pop();
    cout<<st.top();
    return 0;
}
