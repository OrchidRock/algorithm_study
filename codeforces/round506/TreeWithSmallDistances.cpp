#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
const int mod = 1e9+7;

#define LIMIT 200005
int N,K;
vector<int> g[LIMIT];
int ans;
int dfs(int u, int parent, int dep){
    bool need = false;
    bool ok = false;
    //cout << "deep: " << dep << " Node: " << u << endl;
    for(auto &v : g[u]){ // loop access adjacency node
        if(v == parent) continue;
        auto beet = dfs(v,u,dep + 1);
        if(beet == 0) need = true;
        else if(beet == 1) ok = true;
    }
    //cout << "deep: " << dep << "Node: " << u << "need: "<< need << "ok: " << ok << endl;
    if(need){
        if(u > 0){
            ans ++;
        }
        return 1;
    }
    if(ok || dep <= 2){
        return 2;
    }
    return 0;
}
int main(){
    cin >> N;
    for (int i=1; i < N; i++){ // construct ADJ
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(0,-1,0); // why dfs
    cout << ans << endl;
    return 0;
}
