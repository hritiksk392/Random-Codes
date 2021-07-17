#include <iostream>
using namespace std;
int fib[10000]={0};
int n=7;
void toFib(){
    fib[0]=1;
    fib[1]=1;
        for(int i=2;i<n;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
}

int main() {

    cin>>n;
toFib();
for(int i=0;i<n;i++){
    printf("%d ",fib[i]);
}
printf("\n");
int p =fib[n-1]/2;
int r=1;
// Upper half of the pattern
    for(int i=0;i<n-2;i++){
        int c=0;
        while(c!=fib[n-i-1]/2-fib[n-i-2]/2){
            int k;
            for( k=0;k<n-r;k++){
                printf(" ");
            }
            for(k;k<n;k++){
                printf("*");
            }
            c++;
            cout<<"\n";
        }
        r++;
        
    }
//Middle part code for _
    for(int i=0;i<n;i++){
        if(fib[i]%2==0) printf("_");
        else printf("*");
    }
    printf("\n");
 
//Lower part of the pattern;
//Upper wale part ko ultha chalado bss
    r--; // restarting r kyunki upper wale part mein ek baar r++ zyaada ho gaya hoga last loop mein
    for(int i=n-3;i>=0;i--){// 1,1 ko consider mt kro kyunki middle mein aagye
        int c=0;
        while(c!=fib[n-i-1]/2-fib[n-i-2]/2){
            int k;
            for( k=0;k<n-r;k++){
                printf(" ");
            }
            for(k;k<n;k++){
                printf("*");
            }
            c++;
            cout<<"\n";
        }
        r--;
        
    }
     printf("\n");
	return 0;
}
