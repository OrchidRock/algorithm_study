#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> cl(n), cr(n),rl(n),rr(n);
    multiset<int> a, b,c,d;
    for (int i = 0; i < n; i++) {
        cin >> rl[i] >> cl[i] >> rr[i] >> cr[i];
        a.insert(cl[i]); 
        b.insert(cr[i]);
        c.insert(rl[i]);
        d.insert(rr[i]);
    }

    int ansx = 0;
    int ansy = 0;
    for (int i = 0; i < n; i++) {
        a.erase(a.find(cl[i]));
        b.erase(b.find(cr[i]));
        c.erase(c.find(rl[i]));
        d.erase(d.find(rr[i]));
        if(*b.begin() >= *a.rbegin() && *d.begin() >= *c.rbegin()){
            ansy = *b.begin();
            ansx = *d.begin();
            break;
        }
        a.insert(cl[i]); 
        b.insert(cr[i]);
        c.insert(rl[i]); 
        d.insert(rr[i]);
    }
    cout << ansx << " " <<ansy << endl;

    return 0;
}
