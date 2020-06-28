#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    const int n = 200000;
    const int k = 999999929;
    //const int k = 999999503;
    const ll r = 100000000000000000LL%k;
    int a = 1;

    printf("%d %d\n", n, k);
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        a = (ll)a*r%k;
        printf("%d", a);
    }
    putchar('\n');
    
    return 0;
}
