/*********************************************************************************************************************************************
Build a tree from pre-order and in-order outputs
pre-order : 1 2 3 4 8 5 6 7
in-order  : 3 2 8 4 1 6 7 5

ans:             1
             2       5
           3   4    6
              8       7
**********************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int k=0;

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


node* tree_from_pre_in(int n,int s,int e, int *pre,int *inn){
    //base case
    if(s>e){
        return NULL;
    }

    //recursive case
    int l;
    for(l=s;l<=e;l++){
        if(inn[l]==pre[k]){
            break;
        }
    }
    node *n_=new node(inn[l]);
    k+=1;
    n_->left=tree_from_pre_in(n,s,l-1,pre,inn);
    n_->right=tree_from_pre_in(n,l+1,e,pre,inn);
    return n_;
}

int main() {
    int n;
    cin>>n;
    int *pre, *inn;
    pre=new int[n];
    inn=new int[n];
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>inn[i];
    }

    node* root=tree_from_pre_in(n,0,n-1,pre,inn);
    queue <node*> q;
    if(root!=NULL){
        q.push(root);
        q.push(NULL);
    }
    display(q);
    return 0;
}