#include <bits/stdc++.h>
#include "BST.cpp"
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define m 1003
stack<BST*> s;
BST* prev = NULL, mid =NULL, t1=NULL,t2=NULL;
void po(BST *root){
    if(root==NULL) return;
    po(root->left);
    if(mid==NULL) mid = root;
    else if(mid!=NULL){
        prev = mid;
        mid = root;
    }

    if((t1==NULL||t2==NULL)&&prev!=NULL&&mid!=NULL){

        if(t1==NULL&&(prev->data>mid->data)) {
            t1 = prev;
        }

        else if(t2==NULL&&t1!=NULL&&(prev->data>mid->data))
        {
            t2= mid;
        }

    }
    po(root->right);

}
int main(){

    BST b, *root= NULL;
    root = b.insert(root,50);
    b.insert(root,30);
    b.insert(root,10);
    b.insert(root,5);
    b.insert(root,90);
    b.inorder(root);
    cout <<endl;
    po(root);
    cout <<endl;

    while(hasnext()) cout <<next()<<endl;
   // while(hasnext()){
   //  cout <<next()<<" ";
   // }



}