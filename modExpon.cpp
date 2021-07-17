#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define m 1000000007
int N= 100005;
int power(int a ,int b){
  if(b==0) return 1;
  int p= power(a,b/2)%m;
  p = (p*p)%m;
  return (b%2==0)?p%m:((a)*(p))%m; 
}

int modInv(int x){
	return power(x,m-2);
}


int32_t main(){
IOS
int s[N];


	for(int j=0;j<N;j++){
		s[j]=1;
	}
cout <<"Wpw"<<endl;

 return 0;
}

 