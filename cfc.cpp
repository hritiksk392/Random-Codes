#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
// #define m 1000000009
#define int long long
#define pi pair<int,int>




int32_t main(){

	int t;
	cin>>t;
	while(t--){
		int n,s;
		cin>>n>>s;

		int a[20];

		int temp =n;
		int sum=0;
		int j=0;
		while(temp!=0){
			sum+= temp%10;
			a[j++]= temp%10;
			temp/=10;
		}
		int l = j;
		if(sum<=s){
			cout <<"0"<<endl;
			continue;
		}

		int j =l-1;
		int psum=0,ans=0;
		int high = pow(10,l+1);
		while(j>=0){
			if(psum + a[j] >=s){
				break;
			}
			else {
				psum+= a[j--];

			}
		}
		if(j==l-1){
			ans = high - n;
		}

	}
	



	

  return 0;
}
