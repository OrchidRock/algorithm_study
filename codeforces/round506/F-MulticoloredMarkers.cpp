#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//vector<pair<int,int>> f;
const int N = 1000 * 1000;

int lens[N];
int k ;
ll solve(ll a, ll b){
    k = 0;
    for(ll i = 1; i * i <= b; ++i){
        if(b % i == 0){
            lens[k++] = i;
        }
    }
    ll ans = 2*(a+b) + 2;
    ll x = a+b;
    int l = 0;
    for(ll i = 1; i * i <= x;++i){
        if(x % i == 0){
            while(l+1 < k && lens[l+1] <= i)
                ++l;
            if(b/lens[l] <= x/i){
                ans = min(ans,(i+x/i)*2);
            }
        }
    }
    return ans;
}
int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",min(solve(a,b),solve(b,a)));
    return 0;
}
