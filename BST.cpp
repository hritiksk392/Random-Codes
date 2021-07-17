#include "bst.h"
#include <iostream>

using namespace std;

BST :: BST() : data(0), left(NULL), right(NULL){}  
// Parameterized Constructor definition. 
BST :: BST(int value) 
{ 
    data = value; 
    left = right = NULL; 
} 
  
// Insert function definition. 
BST* BST :: insert(BST *root, int value) 
{ 
    if(!root) 
    { 
     return new BST(value); 
    } 
  
  
    if(value > root->data) 
    { 
            root->right = insert(root->right, value); 
    } 
    else
    { 
           root->left = insert(root->left, value); 
    } 
      
    return root; 
} 
 
void BST :: inorder(BST *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    inorder(root->left); 
    cout << root->data << " "; 
    inorder(root->right); 
} 


