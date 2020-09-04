/**************************************************************************************************************************************************
Find all the nodes at adistance of k from the target
input-->
tree: 1 2 4 6 -1 -1 7 10 12 -1 -1 -1 11  7 -1 -1 14 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
target: 4
K: 2
                                      1
                                2           3
                          4    	    5
                      6     7     8   9
                         10   11
                       12    7  14


Output-->
10 11 5 1

************************************************************************************************************************************************/
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

void print_Kth_level(node *root, int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    print_Kth_level(root->left,k-1);
    print_Kth_level(root->right,k-1);
}

int K_dist_from_target(node *root, int tar,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==tar){
        print_Kth_level(root,k);
        return 1;
    }

    int l=K_dist_from_target(root->left,tar,k);
    int r=K_dist_from_target(root->right,tar,k);

    if(l!=-1 && r==-1){
        if(l==k){
            cout<<root->data<<" ";
            return -1;
        }
        if(k>l){
            print_Kth_level(root->right,k-l-1);
            return l+1;
        }
    }

    if(r!=-1 && l==-1){
        if(r==k){
            cout<<root->data<<" ";
            return -1;
        }
        if(k>r){
            print_Kth_level(root->left,k-r-1);
            return r+1;
        }
    }
    return -1;
}

int main() {
    node* root=BUILD_TREE();
    int tar, k;
    cin>>tar>>k;
    K_dist_from_target(root,tar,k);
    return 0;
}