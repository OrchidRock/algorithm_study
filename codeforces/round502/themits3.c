/**
 * one dimension up to two dimension,Prefect!!!! 
 *
 * */

#include <cstdio>

int n;
char a[100010],b[100010];
int main(){
    scanf("%d%s%s",&n,a,b);
    int c[2][2] = {0};
    for(int i=0; i< n ; i++) c[a[i]-'0'][b[i]-'0']++;
    printf("%lld\n",1ll*c[0][0]*(c[1][0]+c[1][1]) + 1ll*c[0][1]*c[1][0]);
}
