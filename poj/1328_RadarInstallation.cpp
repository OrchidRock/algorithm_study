#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define MAX_N 1005

pair<double,double> que[MAX_N];
int N,D;

int main(){
    int casenum = 1;
    while(true){
        int ans = 0;
        scanf("%d %d",&N,&D);
        if(N==0 && D==0) break;
        for(int i=0; i < N;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            if(y>D){
                ans = -1;
            }
            double llen = sqrt(D*D-y*y);
            que[i].first = (double)x-llen;
            que[i].second = (double)x+llen;
        }
        getchar();
        
        if(ans == -1){
            printf("Case %d: -1\n",casenum++);
            continue;
        }
        sort(que,que+N);
        /* 
        for(int i=0; i<N;i++){
            printf("%lf %lf\n",que[i].first,que[i].second);
        }*/
            
        int head = 0;
        while(head < N){
            ans += 1;
            int t = head;
            while(head < N){
                if(!(que[t].first > que[head].second || que[t].second < que[head].first)){
                    que[t].first = min(que[t].first,que[head].first);
                    que[t].second = min(que[t].second,que[head].second);
                    head++;
                }else{
                    break;
                }
            }
        }
        printf("Case %d: %d\n",casenum++,ans);
    }

    return 0;
}
