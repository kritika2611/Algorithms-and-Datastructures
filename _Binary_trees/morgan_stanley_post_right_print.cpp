#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        left=NULL;
        right=NULL;
    }
};

node* Tree(int m){
    int d;
    cin>>d;
    if(d==-1)    return NULL;

    node *root=new node(d);
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    int level=1;

    while(!q.empty() && level<m){
        node *f=q.front();
        q.pop();
        
        if(f==NULL){
            level+=1;
            q.push(NULL);
            continue;
        }
        int left_data,right_data;
        cin>>left_data>>right_data;
        
        if(left_data==-1) f->left=NULL;
        else{
            f->left=new node(left_data);
            q.push(f->left);
        }

        if(right_data==-1) f->right=NULL;
        else{
            f->right=new node(right_data);
            q.push(f->right);
        }
    }
    return root;
}

void display(node *root){
    if(root==NULL){
        return;
    }

    display(root->right);
    display(root->left);
    cout<<root->data<<" ";
}

int main() {
    int n,m;
    cin>>n>>m;

    node* root=Tree(m);
    display(root);
    
    return 0;
}
