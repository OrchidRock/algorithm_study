#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 5005
#define MAX_E 100005
#define INF (1<<30)

struct edge{int from,to,cost;};
vector<edge> G[MAX_N];
int V, E;
int dist[MAX_N];
int dist2[MAX_N];

typedef pair<int,int> P;

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(dist,dist+V,INF);
    fill(dist2,dist2+V,INF);
    dist[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second, d= p.first;
        if(dist2[v] < d) continue;
        for(int i=0; i < G[v].size();i++){
            edge e = G[v][i];
            //printf("%d %d %d\n",e.to,e.from,e.cost);
            
            int d2=d + e.cost;
            if(dist[e.to] > d2){
                swap(dist[e.to],d2);
                que.push(P(dist[e.to],e.to));
            }
            if(dist2[e.to] > d2 && dist[e.to] < d2){
                dist2[e.to] = d2;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }
}

int main(){
    scanf("%d %d",&V,&E);
    for (int i=0; i < E; i++){
        int A,B,D;
        scanf("%d %d %d",&A,&B,&D);
        A--;B--;
        edge e1 = {A,B,D};
        edge e2 = {B,A,D};
        G[A].push_back(e1);
        G[B].push_back(e2);
    }
    dijkstra(0);
    printf("%d\n",dist2[V-1]);
    return 0;
}
