#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define md 1000000007
#define int long long
#define pi pair<int,int>
 
vector<vector<int>> createSparseTree(int a[],int n){
    int p = floor(log2(n));
    vector<vector<int>> dp(n,vector<int> (p+1,-1));

    for(int i=0;i<n;i++) dp[i][0] = a[i];


    for(int j=1 ; (1<<j) <=n ;j++){

        for(int i=0; (i + (1<<j) -1) < n ;i++){

            dp[i][j] = min(dp[i][j-1],dp[i+ (1<<(j-1))][j-1]);
        }
    }

    return dp;    



}

int query(int l,int r , vector<vector<int>> &dp){

     int p = floor(log2(r-l+1));

     int ans = min(dp[l][p],dp[r-(1<<p) +1][p]);

     return ans;

}

int32_t main(){
    IOS

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int q;
    cin>>q;

   vector<vector<int>> dp = createSparseTree(a,n);
   
//   for(int i=0;i<dp.size();i++){
//       for(int j=0;j<dp[0].size();j++){
//           cout <<dp[i][j] <<" ";
//       }
//       cout <<endl;
//   }
    while(q--){

        int l,r;
        cin>>l>>r;
        cout <<query(l,r,dp)<<endl;

    }


 
 
 return 1LL*0;
 
}