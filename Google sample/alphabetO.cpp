#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define m 1003
// #define int long long

 int32_t main(){
  string A="abcdefghbbbbb";
  // cin>>A;
  int l= 0,r=0;
  int  n= A.length();
  int j=0;
  while(j<n-1&&(A[j]==A[j+1])) j++;

if(j==n-1) { cout <<"1"<<endl;}

else{
  if(j<n-1){
    l = (A[j+1]>A[j]);
    r= (A[j+1]<A[j]);  
  }

  int ans=0;
  while(j<n-1){
       while(j<n-1&&A[j]==A[j+1]) j++;
       if(j==n-1) {ans++; break;}
       else{
          l = (A[j+1]>A[j]);
          r= (A[j+1]<A[j]); 
       }

    if(l){
      while((j<n-1)&&A[j+1]>=A[j]){
        j++;
      }
   j++;
     ans++;

    }
    else if (r){

      while((j<n-1)&&(A[j]>=A[j+1])){
        j++;
      }
      
      j++;
      ans++;
      // while(j<n-1&&A[j]==A[j+1]) j++;
   
    }
  }
    

cout <<ans<<endl;
}

 
  return 0;

}
 