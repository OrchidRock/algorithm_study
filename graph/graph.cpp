#include <cstdio>
#include <vector>

using namespace std;

#define MAX_N 10000

vector<int> G[MAX_N];

int main(){
    int V, E;
    scanf("%d %d",&V,&E);
    for (int i=0; i < E; i++){
        int s,t;
        scanf("%d %d",&s,&t);
        G[s].push_back(t);
    }
    return 0;
}
