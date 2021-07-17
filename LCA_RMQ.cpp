#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define md 1000000007
#define int long long
#define pi pair<int,int>

 
vector<vector<pi>> createSparseTree(int a[],int n){
    int p = floor(log2(n));
    vector<vector<pi>> dp(n,vector<pi> (p+1));

    for(int i=0;i<n;i++) dp[i][0] = {a[i],i};


    for(int j=1 ; (1<<j) <=n ;j++){

        for(int i=0; (i + (1<<j) -1) < n ;i++){

            dp[i][j] = min(dp[i][j-1],dp[i+ (1<<(j-1))][j-1]);

            if((dp[i][j-1].first) < (dp[i+ (1<<(j-1))][j-1].first) ){

                dp[i][j] = dp[i][j-1];
            }
            else{
                dp[i][j] = (dp[i+ (1<<(j-1))][j-1]);
            }
        }
    }

    return dp;    



}

int query(int l,int r , vector<vector<pi>> &dp){

     int p = floor(log2(r-l+1));



     if((dp[l][p].first) < (dp[r-(1<<p) +1][p].first ) ){
        return dp[l][p].second;
     }
     else return dp[r-(1<<p) +1][p].second;
    
    
  

}
int tour_index=0;
void dfs(int i,int dep,int depth[],int nodes[],int last[],vector<int> adj[]){

    nodes[tour_index] = i;
    depth[tour_index] = dep;
    last[i] = tour_index;
    tour_index++;

    for(auto l : adj[i]){
        dfs(l,dep+1,depth,nodes,last,adj);

        nodes[tour_index] = i;
        depth[tour_index] = dep;
        last[i] = tour_index;
        tour_index++;
    }

    return ;



}

 vector<vector<pi>> setup(int n, vector<int> adj[],int depth[],int nodes[],int last[]){

    dfs(0,0,depth,nodes,last,adj);

    vector<vector<pi>> sparseTable = createSparseTree(depth,2*n-1);

    return sparseTable;

}

int lca(int id1,int id2 ,int last[],vector<vector<pi>> &dp){

    int l= min(last[id1],last[id2]);
    int r = max(last[id1],last[id2]);
  
    int i = query(l,r,dp);
    return i;
}

int32_t main(){
    IOS
    int n;
    cin>>n;

    vector<int> adj[n];
    for(int i=0;i<n;i++){

        int m;
        cin>>m;
        while(m--){
            int a;
            cin>>a;
            adj[i].push_back(a);

        }
    }
    int q;
    cin>>q;
    int last[n];
    int depth[2*n-1];
    int nodes[2*n-1];

    vector<vector<pi>> sTable = setup(n,adj,depth,nodes,last);
    
    // for(int i=0;i<sTable.size();i++){
    //     for(int j=0;j<sTable[0].size();j++){
    //         cout <<sTable[i][j].first<<","<<sTable[i][j].second<<" ";
    //     }
    //     cout <<endl;
    // }
    while(q--){
        int id1,id2;
        cin>>id1>>id2;
        int index = lca(id1,id2,last,sTable);
        cout <<nodes[index]<<endl;
    }

    


 
 
 return 1LL*0;
 
}