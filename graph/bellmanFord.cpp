#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_N 10000
#define INF (1<<31)

vector<int> G[MAX_N];
struct edge{int from,to,cost;};
edge es[MAX_N];

int d[MAX_N];
int V,E;
void shortest_path(int s){
    for(int i=0; i < V;i++) {
        d[i] = INF;
    }
    d[s] = 0;
    while(true){ // 没有权重为负值的ring
        bool update = false;
        for(int i=0; i < E;i++){
            edge e = es[i];
            if(d[e.from] < INF && d[e.to] > d[e.from] + e.cost){ // 
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
    }

}
bool find_negative_loop(){
    memset(d,0,sizeof(d));
    for (int i=0 ; i < V;i++){
        for(int j=0; j < E;j++){
            edge e = es[i];
            if(d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;

                if(i == V-1) return true;
            }
        }
    }
    return false;
}
int main(){
    scanf("%d %d",&V,&E);
    for (int i=0; i < E; i++){
        int s,t;
        scanf("%d %d",&s,&t);
        G[s].push_back(t);
    }
    //solve();
    return 0;
}
