#include <cstdio>
#include <vector>

using namespace std;

#define MAX_N 21
#define MAX_ANS 11
int W,H;
int G[MAX_N][MAX_N];
//bool flag[MAX_N][MAX_N];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int gx,gy;
int result = MAX_ANS;

bool inSquare(int x,int y){
    return 0<=x && x < H && 0<=y && y < W;
}
void dfs(int sx,int sy,int ans){
    if(sx == gx && sy == gy){
        result = min(result,ans);
        return;
    }
    if(ans == 10 || ans >= result) return;
    
    for(int i=0; i < 4; i++){
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        
        while(inSquare(nx,ny) && G[nx][ny] != 1){
            if(nx == gx && ny == gy){
                ans ++;
                result = min(result,ans);
                return;
            }
            nx += dx[i];
            ny += dy[i];
        }
        if(nx == sx+dx[i] && ny == sy + dy[i] 
                || !inSquare(nx,ny)){
            continue;
        }
        G[nx][ny] = 0;
        ans ++;
        dfs(nx-dx[i],ny-dy[i],ans);
        ans --;
        G[nx][ny] = 1;
    }
}

int main(){
    while(true){
        scanf("%d %d",&W,&H);
        if(!W && !H) break;
        int sx,sy;
        result = MAX_ANS;
        for(int i=0; i < H; i++){
            for(int j=0; j < W;j++){
                int status;
                scanf("%d",&status);
                G[i][j] = status;
                if(status == 2){
                    sx = i;
                    sy = j;
                    G[i][j] = 0;
                }else if(status == 3){
                    gx = i;
                    gy = j;
                }
            }
        }
        dfs(sx,sy,0);
        if(result >= MAX_ANS) printf("-1\n");
        else printf("%d\n",result);
    }
    return 0;
}
