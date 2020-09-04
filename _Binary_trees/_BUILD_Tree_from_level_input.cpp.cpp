/********************************************************************************************************************************************
INPUT: 5
       8 5 15 4 7 12 -1 3 5 6 -1 11 13 -1 -1 -1 -1 9 10 -1 -1

OUTPUT: 8 
        5 15 
        4 7 12 
        3 5 6 11 13 
        9 10 
*******************************************************************************************************************************************/

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

node* _Tree(int l){
    int d;
    cin>>d;
    if(d==-1) return NULL;

    node* root=new node(d);
    queue <node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty() && l-1){
        node* f=q.front();
        q.pop();

        if(f==NULL){
            l-=1;
            if(!q.empty()) q.push(NULL);
            continue;
        }

        int lc,rc;
        cin>>lc>>rc;
        
        if(lc!=-1){ f->left=new node(lc); q.push(f->left); }
        if(rc!=-1){ f->right=new node(rc); q.push(f->right); }
    }
    return root;
}

void print_BFS(node* root){
    if(root==NULL){
        return;
    }

    queue <node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f=q.front();
        q.pop();
        if(f==NULL){ 
            cout<<endl;
            if(!q.empty()) q.push(NULL);
            continue;
        }

        cout<<f->data<<" ";
        if(f->left!=NULL) q.push(f->left);
        if(f->right!=NULL) q.push(f->right);
    }
}

int main(){
    int l;
    cin>>l;
    node* root=_Tree(l);
    print_BFS(root); 
    return 0;
}