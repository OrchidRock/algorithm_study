#include<bits/stdc++.h>
using namespace std;const int N=3007;typedef long long ll;
int n,m,i,j,k;ll ans=1e18,v,cnt;priority_queue<int,vector<int>,greater<int>>e[N],s[N],S;
int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;++i)scanf("%d%d",&j,&k),s[j].push(k);
    for(i=1;i<=n;++i){
        while(!S.empty())S.pop();cnt=s[1].size();
        for(j=2;j<=m;++j)e[j]=s[j];
        for(v=0,j=2;j<=m;++j)while(e[j].size()>=i)v+=e[j].top(),e[j].pop(),cnt++;
        for(j=2;j<=m;++j)while(!e[j].empty())S.push(e[j].top()),e[j].pop();
        for(;cnt<i&&!S.empty();++cnt)v+=S.top(),S.pop();
        if(cnt>=i)ans=min(ans,v);
        printf("%lld\n",ans);
    }printf("%lld\n",ans);
}
