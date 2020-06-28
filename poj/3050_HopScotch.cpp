#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

set<int> result;
int G[5][5];

void bfs(int x,int y,int p,int d){
    p = p*10 + G[x][y];
    if(d==5){
        if(result.find(p) == result.end()){
            result.insert(p);
        }
        return;
    }   
    for(int i=0; i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <0 || nx >=5 || ny <0 || ny>=5) continue;
        bfs(nx,ny,p,d+1);
    }
}
int main(){
    for(int i=0; i < 5;i++){
        for(int j=0;j<5;j++){
            int v ;
            scanf("%d",&v);
            G[i][j] = v;
        }
    }
    for(int i=0; i < 5;i++){
        for(int j=0; j < 5;j++){
            bfs(i,j,0,0);            
        }
    }
    printf("%ld\n",result.size());
    return 0;
}
