#include<bits/stdc++.h>
using namespace std;
long long f[505][505],n,k,ans,mod=998244353;
int main() {
    cin>>n>>k;
    f[0][0]=1;
    for(int i=0;i<n;++i) for(int j=0;j<=i;++j) for(int k=1;k+i<=n;++k){
        f[i+k][max(j,k)]=(f[i+k][max(j,k)]+f[i][j])%mod;
        cout << "f[" << i+k << "," << max(j,k) << "]=" << f[i+k][max(j,k)] << " f[" << i << ","<<j << "]=" << f[i][j] << endl;
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(i*j<k) ans=(ans+f[n][i]*f[n][j])%mod;
    cout<<ans*2%mod<<endl;
    return 0;
}
