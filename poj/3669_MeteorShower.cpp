#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX_T 1001
#define MAX_N 305
#define MAX_D 1000

int M;
int G[MAX_N][MAX_N];
int D[MAX_N][MAX_N];

struct P{int x,y;};
queue<P> que;

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

bool inSquare(int x, int y){
    return x >=0 && y >=0 && x < MAX_N && y < MAX_N;
}

int bfs(){
    que.push(P{0,0});
    D[0][0] = 0;
    while(!que.empty()){
        P p = que.front(); 
        que.pop();
        if(G[p.x][p.y] == MAX_T) return D[p.x][p.y];

        for(int i=0 ; i < 4; i++){
            int nx = p.x + dx[i] ;
            int ny = p.y + dy[i];
            if(nx>=0 && ny>=0 && D[nx][ny] == MAX_D && G[nx][ny] > (D[p.x][p.y]+1)){
                que.push(P{nx,ny});
                D[nx][ny] = D[p.x][p.y] + 1;
            }
        }
    }
    return -1;
}

int main(){
    for(int i=0;i<MAX_N;i++){
        fill(G[i],G[i]+MAX_N,MAX_T);
        fill(D[i],D[i]+MAX_N,MAX_D);
    }
    scanf("%d",&M)  ;
    for(int i=0; i<M;i++){
        int x,y,t;
        scanf("%d %d %d",&x,&y,&t);
        G[x][y] = min(G[x][y],t);
        for(int i=0 ; i < 4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0){
                G[nx][ny] = min(G[nx][ny],t);
            }
        }
    }
    /*
    for(int i=0 ; i < M; i++){
        for(int j=0; j < M;j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }*/
    int ans = bfs();
    printf("%d\n",ans);
    return 0;
}
