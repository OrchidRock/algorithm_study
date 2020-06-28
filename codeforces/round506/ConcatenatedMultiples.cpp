#include <bits/stdc++.h>
using namespace std;
#define LIMIT 200005
typedef long long ll;
ll a[LIMIT];
ll r[10];
ll remainder(ll p, ll num,ll k){
    p = p % k;
    int count = 0;
    while(num != 0){
        count += 1;
        num /= 10;
    }
    return ((p*r[count])%k);
}
int main(){
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll tmp = 1;
    r[0] = 1;
    for(int i=1;i<=9;i++){
        r[i] = (r[i-1]*10)%k;
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        //printf("%lld\n",a[i]);
    }
    ll count = 0;
    for(int i=0; i< n;i++){
        for(int j=i+1; j<n;j++){
            ll m = a[i] % k;
            ll n = a[j] % k;
            ll mraminder = remainder(a[i],a[j],k); 
            ll nraminder = remainder(a[j],a[i],k); 
            if((m+nraminder)%k ==0){
                count+=1;
            }
            if((mraminder+n)%k == 0){
                count +=1;
            }
        }
    }
    printf("%lld\n",count);
    return 0;
}
