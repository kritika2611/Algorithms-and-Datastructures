#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* TREE(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    node *n=new node(d);
    n->left=TREE();
    n->right=TREE();
    return n;
}

void display(queue <node*> q){
    if(q.empty()){
        return;
    }
    while(!q.empty()){
        node *f=q.front();
        q.pop();
        if(f==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<f->data<<" ";
            if(f->left!=NULL){
                q.push(f->left);
            }
            if(f->right!=NULL){
                q.push(f->right);
            }
        }
    }
}

int main(){
    node *root=TREE();
    queue <node*> q;
    if(root!=NULL){
        q.push(root);
        q.push(NULL);
    }
    display(q);
    return 0;
}