#include <cstdio>
#include <vector>

using namespace std;
#define MAX_N 10005
int N,S;
int C[MAX_N];
int Y[MAX_N];

int main(){
    long long sum = 0;
    scanf("%d %d",&N,&S);
    for(int i=0 ; i < N;i++){
        int c,y;
        scanf("%d %d",&c,&y);
        C[i] = c;
        Y[i] = y;
    }
    for(int i=1;i<N;i++){
        C[i] = min(C[i-1]+S,C[i]);
    }
    for(int i=0;i<N;i++){
        sum+=C[i]*Y[i];
    }
    printf("%lld\n",sum);
    return 0;
}
