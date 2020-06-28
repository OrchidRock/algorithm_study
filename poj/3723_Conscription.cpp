#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 20005
#define MAX_E 100005
#define MAX_R 50005

#define INF (1<<31)

int par[MAX_N];
int r[MAX_N];

void init_union_find(int n){
    for(int i=0; i < n; i++){
        par[i] = i;
        r[i] = 0;
    }
}

int find(int x){
    if(x != par[x]){
        par[x] = find(par[x]);
    }
    return par[x];
}

void unite(int x,int y){
    x = find(x);
    y = find(y);

    if (x == y) return;
    if(r[x] < r[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(r[x] == r[y]) r[x] ++;
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}


struct edge{int from,to,cost;};
edge es[MAX_E];
int V,E;
int X[MAX_R];
int Y[MAX_R];
int D[MAX_R];
int N,M,R;

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

int kruskal(){
    sort(es,es+E,comp);
    init_union_find(V);
    int res = 0;
    for(int i=0; i < E;i++){
        edge e = es[i];
        if(!same(e.from,e.to)){
            unite(e.from,e.to);
            res += e.cost;
        }
    }
    return res;
}
void solve(){
    V = N + M;
    E = R;
    for(int i=0; i < R;i++){
        es[i] = (edge){X[i],N+Y[i],-D[i]};
    }
    printf("%d\n",10000 * V + kruskal());
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&N,&M,&R);
        for (int i=0; i < R; i++){
            int x,y,d;
            scanf("%d %d %d",&x,&y,&d);
            X[i] = x;
            Y[i] = y;
            D[i] = d;
        }
        solve();
    }
    return 0;
}


