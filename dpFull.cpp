#include<bits/stdc++.h>
using namespace std;
string pal(string a){
  string z;
    int n=a.length(),i,j,start,max=1,k;
    bool res[n][n];
    memset(res,0,sizeof(res));
    for(i=0;i<n;i++){
        res[i][i]=true;
    }
    for(i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            res[i][i+1]=true;
            max=2;
            start=i;
        }
    }
    for(k=3;k<=n;k++){
        for(i=0;i<n-k+1;i++){
            j=i+k-1;
            if(res[i+1][j-1]==true&&a[i]==a[j]){
                res[i][j]=true;
                if(k>max){
                    max=k;
                    start=i;
                }
            }
        }
    }
    z.append(a,start,max);
    return z;
}
int main(){
  string s="aaaabaaa";
  cout<<pal(s);
}