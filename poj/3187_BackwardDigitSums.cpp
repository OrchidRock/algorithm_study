#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX_N 10
// M >= n
int permutation(int m,int n){
    if(n==0 || m==n) return 1;
    int k = max(n,m-n)+1;
    int p = 1;
    while(k<=m){
        p = p * k;
        k++;
    }
    int q = 1;
    k = min(n,m-n);
    while(k>=1){
        q = q*k;
        k--;
    }
    return p/q;
}
int main(){
    int N,S;
    int d[MAX_N];
    long long ans = 0;
    scanf("%d %d",&N,&S);
    for(int i=0;i<N;i++) d[i]=i+1;
    do{
        ans = 0;
        for(int i=0; i < N;i++){
            ans += d[i]*permutation(N-1,i);
        }
        if(ans == S) break;
    }while(next_permutation(d,d+N));
    for(int i=0; i < N;i++){
        printf("%d ",d[i]);
    }
    printf("\n");
    return 0;
}
