#include <cstdio>
#include <vector>

using namespace std;

#define MAX_N 21
int W,H;
char G[MAX_N][MAX_N];
bool flag[MAX_N][MAX_N];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int dfs(int x,int y){
    flag[x][y] = true;
    int ans = 0;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx < 0 || nx>=H) continue;
        if(ny < 0 || ny>=W) continue;
        
        if(G[nx][ny] == '.' && !flag[nx][ny]){
            ans += dfs(nx,ny) + 1;
        }
    } 
    return ans;
}

int main(){
    while(true){
        scanf("%d %d",&W,&H);
        if(W==0 && H==0) break;
        char line[MAX_N];
        int m,n;
        int ans = 1;
        for(int i=0; i < H; i++){
            scanf("%s",line);
            for(int j=0; j < W; j++){
                G[i][j] = line[j];
                if(line[j] == '@'){
                    m = i;
                    n = j;
                }
            }
        }
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++){
                flag[i][j] = false;
            }
        }
        //printf("%d %d\n",m,n);
        ans = dfs(m,n) + 1;
        printf("%d\n",ans);

    }
    return 0;
}
