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

node* Tree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node *n=new node(d);
    n->left=Tree();
    n->right=Tree();
    return n;
}

int max_path_sum(node *root, int &max_path){
    int p;
    if(root==NULL){
        return 0;
    }

    int l=max_path_sum(root->left,max_path);
    int r=max_path_sum(root->right,max_path);
    //best path
    if(l<0 && r<0)
        p=root->data;
    else
        p=root->data+max(l,r);

    //calculating path length
    int path;
    if(r<0 && l<0) path=root->data;  
    else if(l<0)  path=root->data+r;
    else if(r<0) path=root->data+l;
    else path=root->data+r+l;

    if(max_path<path){
        max_path=path;
    }
    return p;
}

int main() {
    node* root=Tree();
    int max_path=INT_MIN;
    max_path_sum(root,max_path);
    cout<<max_path;
    return 0;
}
