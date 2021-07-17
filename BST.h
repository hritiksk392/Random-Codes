#ifndef BST_h
#define BST_H

class BST 
{ 	public:
    int data; 
    BST *left, *right; 
    public:       
    BST(); 
    BST(int); 
    BST* insert(BST *, int); 
    void inorder(BST *); 
}; 
#endif