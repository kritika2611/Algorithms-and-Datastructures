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

class Pair_{
public:
    int height;
    bool balanced;
};

Pair_ height_balanced(node *root){
    if(root==NULL){
        Pair_ p;
        p.height=0;
        p.balanced=true;
        return p;
  }
    if(root->left==NULL && root->right==NULL){
        Pair_ p;
        p.height=1;
        p.balanced=true;
        return p;
    }

    Pair_ l=height_balanced(root->left);
    Pair_ r=height_balanced(root->right);
    Pair_ ans;
    ans.height=max(l.height,r.height)+1;
    int diff=abs(r.height-l.height);
    if(r.balanced==false || l.balanced==false){
        ans.balanced=false;
    }
    else if(diff<=1){
        ans.balanced=true;
    }
    else{
        ans.balanced=false;
    }
    return ans;
}


int main() {
    node* root=Tree_();
    queue <node*> q;
    if(root!=NULL){
        q.push(root);
        q.push(NULL);
    }
    display(q);
    cout<<endl;
    Pair_ p=height_balanced(root);
    if(p.balanced){
        cout<<"Balanced Height";
    }
    else{
        cout<<"Height not balanced";
    }
    return 0;
}
