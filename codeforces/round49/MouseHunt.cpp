#include <bits/stdc++.h>

using namespace std;

#define N 200005
#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a<b)?b:a)

typedef struct{
    int num;
    void* next;
}Node;

int main(){
    int n =0;
    scanf("%d",&n);
    int c[N];
    int a[N];
    int r[N][3]; // ring array
    int result = 0;
    int path[N] = {0};
    for (int i = 1; i < n+1; i++) scanf("%d",c+i);
    for (int i = 1; i < n+1; i++) scanf("%d",a+i);
    for (int i=1; i<n+1;i++){
        int j = i;
        int mincost = c[j];
        path[0] = j;
        int path_len = 1;
        while(1){
            int ring = 0;
            //int ringmin = 2e4+5;
            for(int k = path_len-1; k >=0 ; --k){
                //ringmin = min(ringmin,path[k]);
                if(a[j] == path[k]){ // ring
                    ring = 1;
                    break;
                }  
            }
            if(ring) break;
            mincost = MIN(mincost,c[a[j]]);
            path[path_len++] = a[j];
            j = a[j];
        }
        printf("i = %d mincost = %d\n",i,mincost);
        result = MAX(result,mincost); 
    }
    printf("%d\n",result);
    return 0;
}
