/**
 * a1 = b1 + x1*a2
 * a2 = b2 + x2*a3
 * a3 = b3 + x3*a4
 * ...
 * ai = bi + xi * a[i+1]
 * ...
 * an = bn = xn*a1
 * Note: if ai == bi only if xi == 0 and b[i-1] < b[i] 
 * 
 * 找到 a[n]=b[n] 
 * ai = bi + b[i+1] + b[i+2] + ... + b[n-1] + 2*b[n]
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 140582+5;
int main(){
    int n = 0;
    ll nxt;
    ll b[N];
    ll a[N];
    cin >> n;
    for (int i=0; i <n;i++) scanf("%lld",b+i);
    int i;
    for(i=0;i<n;i++){
        if(i == 0){
           if(b[0] > b[n-1]) break;
           else continue;
        }
        if(b[i] > b[i-1])
            break;
    }
    if(i>=n){
        if(b[n-1]) cout << "NO" <<endl;
        else for(cout << "YES" << endl,i=0;i<n;i++) printf("1 ");
        return 0;
    }
    cout << "YES" << endl;
    a[i] = b[i];
    ll x = (i-1 + n)%n;
    //cout << i << endl;
    //cout << a[i] << endl;
    while(x != i){
        //cout << x<<endl;
        if(b[(x-1+n)%n] < b[x]) a[x] = b[x];
        else{
            nxt = a[(x+1)%n];
            a[x] = b[x] + nxt * ((b[(x-1+n)%n] - b[x]) / nxt + 1);
        }
        x = (x-1+n)%n;
    }
    for(int j=0; j < n;j++) printf("%lld ",a[j]);
    printf("\n");
    return 0;
}
