#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N =1e5 +5;
int vis[100005] ={0};
// string reverse(string s){
//   string out=s;
//   for(int i=0;i<s.length()/2;i++){
//     swap(out[i],out[n-1-i]);
//   }
//   return out;

// }
 

int32_t main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a,a+n);
    int b[n];
    int t=0;
    if(n%2==0){
    for(int i=n/2;i>=0;i--){
      
        b[t++]=a[i];
        b[t++]= a[n-i-1];
      

    }
  }
  else{
    b[t++] = b[n/2];
    for(int i=(n/2+1);i<n;i++){
       b[t++]=a[i];
        b[t++]= a[n-i-1];
    }
  }
for(auto l :b) cout<<b[i];

    }
    return 0;
 
 
   }