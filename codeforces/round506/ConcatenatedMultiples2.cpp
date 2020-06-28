#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, x;
map<int, int> cnt[11], fk[11];

int len(int a) {
    for(int i=1;i<11;i++) {
        a /= 10;
        if(!a) return i;
    }
    return 11;
}

int main() {
    cin >> n >> k;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        scanf("%d", &x);
        int l = len(x);
        ans += cnt[l][(k-x%k)%k];
        int y = x%k;
        for(int j=0;j<11;j++) {
            ans += fk[j][(k-y)%k];
            ++cnt[j][y%k];
            y = 1LL * y * 10 % k;
        }
        ++fk[l][x%k];
    }
    cout << ans << endl;
    return 0;
}
