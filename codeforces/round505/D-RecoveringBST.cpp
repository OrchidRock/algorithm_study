#include <bits/stdc++.h>

using namespace std;
#define N 707
bool dp[N][N][2];
int a[N];
bool f[N][N];
bool ok(int a,int b,bool e){
    if(a>b) return true;
    return dp[a][b][e];
}
int gcd(int a,int b){
    while(b){
        int t = a%b;
        a = b;
        b= t;
    }
    return a;
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i+1];
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            f[i][j] = gcd(a[i],a[j]) > 1;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][i][0] = f[i][i-1];
        dp[i][i][1] = f[i][i+1];
    }
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1 <=n;l++){
            int r = l+len-1;
            for(int root=l;root <=r;root++){
                bool okTree = ok(l,root-1,1) && ok(root+1,r,0);
                dp[l][r][0] = dp[l][r][0] || (okTree && f[l-1][root]);
                dp[l][r][1] = dp[l][r][1] || (okTree && f[r+1][root]);
            }
        }
    }
    cout << (dp[1][n][0] ? "YES" : "NO") << endl;
    return 0;
}
