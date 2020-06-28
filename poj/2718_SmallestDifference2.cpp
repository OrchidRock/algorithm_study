#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        char c;
        int count=0;
        int d[11];
        int ans = 10000000;
        while((c=getchar()) != '\n'){
            //putchar(c);
            if(c!=' '){
                d[count++] = c-'0';
            }
        }
        do{
            int x=0,y=0;
            if(!d[0] || !d[count/2] && count>2){
                continue;
            }
            for(int i=0; i < count/2;i++) x = x*10 + d[i];
            for(int i=count/2;i<count;i++) y = y*10 + d[i];
            ans = min(ans,abs(x-y));
        }while(next_permutation(d,d+count));
        printf("%d\n",ans);
        /*
           for(int i=0 ; i < count; i++){
           printf("%d",d[i]);
           }*/
    }
    return 0;
}
