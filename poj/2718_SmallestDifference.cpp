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
	sort(d,d+count);
        int x = 0;
        int y = 0;
        if(count % 2 != 0){
            for(int i =0; i <= count/2;i++){
                if(i==0 &&  d[i]==0){
                    x += d[1]*10 + d[0];
                    i+=1;
                    continue;
                }
                x = x*10 + d[i];
            }
            for(int i=count-1; i > count/2;i--){
                y = y*10 + d[i];
            }
            ans = x -y;
        }else{
            for(int i= count-1; i>=1; i--){
                for(int j=i-1;j>=0;j--){
		    if(j==0 && d[j] == 0) continue;
                    x = d[i];
                    y = d[j];
                    for(int k=0,c=1;k<count && c < count/2;k++){
                        if(k==i || k == j) continue;
                        x = x*10 + d[k];
                        c++;
                    }
                    for(int k=count-1,c=1;k>=0 && c < count/2;k--){
                        if(k==i || k == j) continue;
                        y = y*10 + d[k];
                        c++;
                    }
                    ans = min(ans,x-y);
                }
            }
        }
        printf("%d\n",ans);
        /*
           for(int i=0 ; i < count; i++){
           printf("%d",d[i]);
           }*/
    }
    return 0;
}
