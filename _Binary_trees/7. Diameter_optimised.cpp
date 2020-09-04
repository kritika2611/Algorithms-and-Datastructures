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

pair<int,int> diameter(node *root){
    //base case
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    //recursive case
    pair <int,int> l=diameter(root->left);
    pair <int,int> r=diameter(root->right);

    pair <int,int> p1;
    p1.first=max(l.first,r.first)+1;
    p1.second=max(l.first + r.first, max(l.second, r.second));     //first is height and second is diameter
    return p1;
}

int main(){
    node *root=TREE();
    pair <int,int> p=diameter(root);
    cout<<"Height: "<<p.first<<endl;
    cout<<"Diameter: "<<p.second;
    return 0;
}