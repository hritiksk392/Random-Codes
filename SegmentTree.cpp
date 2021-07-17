#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

void construct(int a[],int seg[],int l,int h, int pos){
	if(l==h) 
		{seg[pos] =a[l];	return;}
	int mid = l + (h-l)/2;

	construct(a,seg,l,mid,2*pos+1);
	construct(a,seg,mid+1,h,2*pos+2);

	seg[pos] = seg[2*pos+1]+seg[2*pos+2];
}

int minq(int seg[],int ql,int qh,int l, int h,int pos){
	if(ql<=l&&qh>=h) return seg[pos];

	if(qh<l||ql>h) return INT_MAX;

	int mid = l + (h-l)/2;

	return min(minq(seg,ql,qh,l,mid,2*pos+1),minq(seg,ql,qh,mid+1,h,2*pos+2));


}
int sumq(int seg[],int ql,int qh,int l, int h,int pos){
	if(ql<=l&&qh>=h) return seg[pos];
	if(qh<l||ql>h) return 0;
	int mid = l + (h-l)/2;

	return sumq(seg,ql,qh,l,mid,2*pos+1) +sumq(seg,ql,qh,mid+1,h,2*pos+2);

}
void updateU(int seg[],int l ,int h, int i,int diff,int pos){
	if(i<l||i>h) return;
	seg[pos]=seg[pos]+diff;

	if(l!=h){
		int mid = l + (h-l)/2;

		updateU(seg,l,mid,i,diff,2*pos+1);
		updateU(seg,mid+1,h,i,diff,2*pos+2);
	}
}
void update(int a[],int seg[],int i, int value,int n){
	int diff = value - a[i];

	updateU(seg,0,n-1,i,diff,0);
}

int main(){
int n =5;
int a[5]= {5,3,8,1,-1};
int x= (int)(ceil(log2(n)));
int m = 2*((int)pow(2,x)) -1;
cout <<m<<endl;
int seg[m];
memset(seg,0,sizeof(seg));

construct(a,seg,0,4,0);
// for(auto l: seg) cout <<l<<" ";
// 	cout <<endl;
cout<<sumq(seg,0,4,0,4,0)<<endl;
update(a,seg,2,9,n);
// for(auto l: seg) cout <<l<<" ";
// 	cout <<endl;
cout<<sumq(seg,0,4,0,4,0);


}