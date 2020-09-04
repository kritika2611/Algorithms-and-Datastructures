/**********************************************************************************************************************************************
replace the parent node with the sum of all its descendents
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

node* Tree_(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* n=new node(d);
    n->left=Tree_();
    n->right=Tree_();
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
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }

        cout<<f->data<<" ";
        if(f->left!=NULL) q.push(f->left);
        if(f->right!=NULL) q.push(f->right);
    }
}

int sum_child(node * root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }

    int l=sum_child(root->left);
    int r=sum_child(root->right);
    int temp=root->data;
    root->data=l+r;
    return root->data+temp;
}

int main() {
    node* root=Tree_();
    queue <node*> q;
    if(root!=NULL){
        q.push(root);
        q.push(NULL);
    }
    display(q);
    sum_child(root);
    cout<<endl;
    display(q);
    return 0;
}
