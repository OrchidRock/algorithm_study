#include <cstdio>
#include <vector>

using namespace std;

#define MAX_N 10000
struct vertex{
    vector<vertex*> edge;
    /*
     * 顶点的其他属性
     */
};
vertex G[MAX_N];

int main(){
    int V, E;
    scanf("%d %d",&V,&E);
    for (int i=0; i < E; i++){
        int s,t;
        scanf("%d %d",&s,&t);
        G[s].edge.push_back(&G[t]);
    }
    return 0;
}
