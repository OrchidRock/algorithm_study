#define MAX_N 10000
int par[MAX_N];
int rank[MAX_N];


void init(int n){
    for(int i=0; i < n; i++){
        par[i] = i;
        rank[i] = 0;
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
    if(rank[x] < rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x] ++;
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}
