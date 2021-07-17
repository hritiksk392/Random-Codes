#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
// #define m 1003
vector<int> LPS(string s){
	int m = s.length();
	int j=0,i=1;
	vector<int> lps(m,0);
	while(i<m){
		if(s[i]==s[j]){
			lps[i]= j+1;
			i++;
			j++;

		}
		else{
			if(!j){
				lps[i++]=0;
			}
			else{
				j= lps[j-1];
			}

		}
	}
	return lps;
}

void search(string s ,string pat){
	int n= s.length();
	int m = pat.length();
vector<int> lps = LPS(pat); 
	int i =0,j=0;
	while(i<n){
		if(pat[j]==s[i]){
			i++;
			j++;
		}
		if(j==m){
			cout <<"Found :"<<i-j<<endl;
		j   = lps[j-1];	}
		else if(i<n&&pat[j]!=s[i]){
			if(j){
				j=lps[j-1];
			}
			else i++;
		}
	}


}

int main(){
	string s = "ABABAC";
	string pat= "ABA";
	search(s,pat);

	return 0;

}