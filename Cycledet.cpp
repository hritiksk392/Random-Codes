#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
// #define m 1003
// #define int long long

bool dfs(int l, unordered_set<int> &wt,unordered_set<int> &gt,unordered_set<int> &bt,vector<int> adj[]){
  wt.erase(wt.find(l));
  gt.insert(l);

  for(auto r : adj[l]){
    if(bt.find(r)!=bt.end()) continue;

    if(gt.find(r)!=gt.end()) return true;

    if(dfs(r,wt,gt,bt,adj)) return true;

  }
  gt.erase(gt.find(l));
  bt.insert(l);
  return false;
}

bool sol(int A,vector<int> B,vector<int> C){
  int n =A;
  int m = B.size();
  vector<int> adj[n+1];

  for(int i=0;i<m;i++){
    adj[B[i]].push_back(C[i]);

  }

  unordered_set<int> wt,gt,dt;

  for(int i=1;i<=A;i++){
    wt.insert(i);
  }
while(wt.size()>0){
  int t= *(wt.begin());
  if(dfs(t,wt,gt,dt,adj)) return true;

}
return false;

}



int32_t main(){
  IOS
  int A = 3;
  vector<int> B = {1,2};
  vector<int> C= {2,3};

  cout <<sol(A,B,C);


 return 0;
}
 