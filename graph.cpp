#include <bits/stdc++.h>
using namespace std;
#define pb push_back()
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n";

void bfs(vector<int> adj[],int s){
	int vis[1000]={0};
	queue<int> q;
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		cout <<f<<" ";
		for(auto x : adj[f]){
			if(!vis[x]){
				
				vis[x]=1;
				q.push(x);
			}
		}
	}

}
void dfsU(vector<int> adj[],int vis[],int s){
	if(vis[s]) return;

	vis[s]=1;
	cout << s<<" ";

	for(auto x :adj[s]){
		if(!vis[x]){
			dfsU(adj,vis,x);
		}
	}

}

void dfs(vector<int> adj[],int s){
	  int vis[1000]={0};


	dfsU(adj,vis,s);

}
int main(){
	int n,m;
	cin>>n>>m;

	vector<int> adj[n];

	while(m--){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs(adj,0);
	cout <<endl;
	dfs(adj,0);

}
