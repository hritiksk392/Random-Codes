#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
// #define m 1003
// #define int long long

int find(int x,int parent[]){
if(x==parent[x]) return x;
  
  while(x!=parent[x]) x= parent[x];
  return x;
}
void merge(int x,int y,int parent[],int rank[]){
  x= find(x,parent);
 y= find(y,parent);

  if(rank[x]>rank[y])
    parent[y]=x;
  else parent[x]=y;

  if(rank[x]==rank[y])
    rank[y]++;
}



int sol(int A,vector<vector<int>> B){
int n =A;
int parent[n+1];
int rank[n+1];

for(int i=1;i<=n;i++){
  parent[i]=i;
  rank[i]=0;
}

// vector<pair<int,int>> adj[n+1];
vector<pair<int ,pair<int,int>>> edge;

for(auto l : B){
  edge.push_back({l[2],{l[0],l[1]}});

}
sort(edge.begin(), edge.end());
int mnwt=0;
for(auto l :edge){
  int w = l.first;
  int u = l.second.first;
  int v = l.second.second;

 int su= find(u,parent);
  int sv =find(v,parent);

  if(su!=sv){
  mnwt+=w;
  merge(su,sv,parent,rank);
  }

}

return mnwt;

}



int32_t main(){
  IOS
  int A = 4;

  vector<vector<int>> B= {
      {1,2,1},{2,3,2},{3,4,4},{1,4,3}
  };


cout <<sol(A,B);
 return 0;
}
 