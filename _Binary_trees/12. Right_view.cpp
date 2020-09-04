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

node* BUILD_TREE(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    node* n=new node(d);
    n->left=BUILD_TREE();
    n->right=BUILD_TREE();
    return n;
}

void right_view(node* root, int l){
    static int max_=INT_MIN;
    if(root==NULL){
        return;
    }

    if(l>max_){
        cout<<root->data<<" ";
        max_=l;
    }
    right_view(root->right,l+1);
    right_view(root->left,l+1);

}

int main() {
    node* root=BUILD_TREE();
    right_view(root,0);
    return 0;
}