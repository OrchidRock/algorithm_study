#include <bits/stdc++.h>

using namespace std;
#define MAX(a,b) ((a<b)?b:a)
const int A = 1e4+5, N = 1e6+6;
int a[N];

int main(){
    int t = 0;
    scanf("%d",&t);
    while(t--){
        int n = 0;
        scanf("%d",&n);
        for(int i =0 ; i< n;i++){
            scanf("%d",a+i);
        }
        sort(a,a+n);
        /*for(int i =0 ; i< n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");*/
        int p = -1;
        int q = -1;
        int last = -1;
        int m = (1<<30);
        for(int i = 0; i < n;){
            if(i-1 >= 0 && a[i] == a[i-1]){
                if(a[i] == last){ 
                    p=last;
                    q=last;
                    break;
                }
                else if( p == -1) p = a[i];
                else if(q == -1) q = a[i];
                else if(p == q) break;
                else{
                    int t = MAX(last,q);
                    if((float)(a[i]-t)/(float)a[i] < (float)(q-p)/(float)q){
                        p = t;
                        q = a[i];
                    }
                }
                last = a[i];
                i += 2;
            }else{
                i += 1;
            }
        }
        printf("%d %d %d %d\n",p,p,q,q);
    }
    return 0;
}

