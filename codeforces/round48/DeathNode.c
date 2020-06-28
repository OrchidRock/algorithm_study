#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 200000

int main(){
    unsigned int n = 0;
    unsigned int m = 0;
    unsigned int alist[MAX_LEN];
    unsigned int tlist[MAX_LEN];
    scanf("%u",&n);
    scanf("%d",&m);

    int i = 0;
    for(i = 0; i < n;i++){
        scanf("%u",&alist[i]);
    }
    unsigned int d = m;
    for(i=0; i < n; i++){
        unsigned int ti = 0;
        if (alist[i] < d){
            d -= alist[i];
        }else if(alist[i] == d){
            d = m;
            ti +=1;
        }else{
            ti = ti + (alist[i] - d)/m + 1;
            d = m - (alist[i] -d)%m;
        }
        //printf("d = %d i = %d\n",d,i);
        tlist[i] = ti;
    }
    for(i = 0; i < n-1;i++){
        printf("%u ",tlist[i]);
    }
    printf("%u\n",tlist[n-1]);
    return 0;
}
