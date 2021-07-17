#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define m 1003

struct TrieNode{
	struct TrieNode * child[26];
	int isWord;

};
typedef struct TrieNode TrieNode;
TrieNode* getNode(void){
	TrieNode* root = new TrieNode();

	for(int i=0;i<26;i++)
	root->child[i]= NULL;

	root->isWord = 0;

	return root; 
}

int insert(TrieNode * root,string key){
	TrieNode* temp = root;
	int flag=0;
	int n = key.length();
	for(int i=0;i<key.length();i++){
		int index = key[i]-'a';

		if(temp->child[index]==NULL)
		temp->child[index] = getNode();
		if(temp->isWord>0) flag=1;
		temp= temp->child[index];
	}
	temp->isWord++;
	return flag;

}
int search(TrieNode* root,string key){
	TrieNode * temp =root;
	int n = key.length();
	for(int i=0;i<n;i++){
		int index = key[i]-'a';
		if(temp->child[index]==NULL) return 0;

		temp= temp->child[index];
	}
	if((temp!=NULL)&&(temp->isWord)){
		return temp->isWord;
	}
	else return 0;

}

int empty(TrieNode* root){

	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL) return false;
	}
	return true;

}

TrieNode* remove(TrieNode * root, string key,int depth){
if(!root) return NULL;

if(depth == key.length()){

	if(root->isWord>0) (root->isWord)--;

	if(!(root->isWord)&&empty(root)){
		delete root;
		return NULL;
	}
return root;
}

int index = key[depth]-'a';
root->child[index] = remove(root->child[index],key,depth+1);

if(empty(root)&&(!(root->isWord))){
	delete root;
	return NULL;
}
return root;

}
int main(){
	string s1="abc",s2="abd",s3="their",s4="there";
	TrieNode* root =getNode();

	vector<string> vs = {"aab","aac","aacghgh","aabghgh"};


	for(auto l: vs){
		int t =insert(root,l);
		if(t) cout << l<<endl;
 	}
	
}