#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		ll x,y,a,b;
		cin>>x>>y;
		cin>>a>>b;
		
		ll m = min(x,y);
		ll d= max(x,y)- min(x,y);

		ll cost1= m*b + d*a;
		ll cost2 = x*a + y*a;
		cout << min(cost1,cost2)<<endl;
	}
	return 0;


}