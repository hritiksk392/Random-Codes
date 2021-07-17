#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define m 1003
struct Trie {
	int Words;
	unordered_map<char,struct Trie*> mp;
};

typedef struct Trie Trie;

Trie* getNode(void){
	Trie *root= new Trie;
	root->Words =0;
	root->mp.clear();
	return root;
}
void insert(Trie *root,string key){
	if(root==NULL) root= getNode();

	Trie*temp= root;
	int n = key.length();
	for(int i=0;i<n;i++){
		char c = key[i];
		if(temp->mp.find(c)==temp->mp.end())
			temp->mp[c] =getNode();
		temp =temp->mp[c];
	}
	temp->Words++;
}
int search(Trie *root,string key){
	if(root==NULL) return 0;
	Trie* temp= root;

	int n= key.length();
	for(int i=0;i<n;i++){
		if(temp->mp.find(key[i])==temp->mp.end())
			return 0;
		temp = temp->mp[key[i]];
	}

	return (temp->Words>0);

}


int main(){
  
  Trie* root = getNode();

vector<string> vs = {"abab", "ab", "abcd"};

  for(auto l: vs){
    insert(root,l);
  }
  search(root,"a")?cout<<"Yes":cout<<"Np";

  
}