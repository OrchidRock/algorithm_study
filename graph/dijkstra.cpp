#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 10000
#define INF (1<<31)

struct edge{int from,to,cost;};
vector<edge> G[MAX_N];
int V, E;
int d[MAX_N];
typedef pair<int,int> P;

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    d[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i < G[v].size();i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main(){
    scanf("%d %d",&V,&E);
    for (int i=0; i < E; i++){
        int s,t;
        scanf("%d %d",&s,&t);
    }
    return 0;
}
