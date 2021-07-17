#include <bits/stdc++.h>
#include "BST.cpp"
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define m 1003
stack<BST*> s;

int next(){
    BST* cur = s.top();
    int v = cur->data;
    s.pop();
    cur= cur->right;
    while(cur!=NULL){
        s.push(cur);
        cur = cur->left;
    }
    return v;
}

bool hasnext(){
    if(s.empty()) return false;
    else return true;
}

void po(BST *root){
    while(!s.empty()) s.pop();
    BST*curr = root;
    while(curr!=NULL){
        s.push(curr);
        curr=curr->left;
    }
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