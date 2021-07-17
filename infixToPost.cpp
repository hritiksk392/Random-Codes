#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define m 1000000007
// Infix to Prefix Code sample
int pre(char x){
	if(x=='^') return 4;
	if(x=='-'||x=='+') return 2;
	if(x=='*'||x=='/') return 3;

	return -1;
}

//Infix to PostFix
string postFix(string exp){
	stack<char> s;
	string out = "";
	int n = exp.length();
	int pr=-1;
	for(int i=0;i<n;i++){
		if(exp[i]=='(') s.push('(');

		else if(exp[i]==')'){
			while(s.top()!='('){
				out.push_back(s.top());
				s.pop();
			}
			s.pop();
		}

		else if(pre(exp[i])==-1) out.push_back(exp[i]);

		else{
			while(!s.empty()&&s.top()!='('&&pre(s.top())>=pre(exp[i])) {
				out.push_back(s.top());
				s.pop();
			}
			s.push(exp[i]);

		}

	}

while(!s.empty()){
	out.push_back(s.top());
	s.pop();
}
return out;


}


int32_t main(){
	string exp ="x+5-3+x";
	string rev="";
	int n  =exp.length();
	for(int i=n-1;i>=0;i--){
		if(exp[i]=='('){
			rev+= ')';
			continue;
		}
		else if (exp[i]==')'){
			rev+='(';
			continue;
		}
		rev +=exp[i];
	}
	cout <<rev<<endl; //Reverse the Infix input

	string post=	postFix(rev); // Find it's PostFix
	reverse(post.begin(), post.end()); // reverse it
	cout<<post<<endl; // Here is your answer!!






	return 0;

}