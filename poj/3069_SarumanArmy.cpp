#include <cstdio>
#include <iostream>
#include<algorithm>
using namespace std;

#define MAX_N 1005

int N,R;
int X[MAX_N];
void solve(){
    sort(X,X+N);
    int i=0;
    int ans = 0;
    while(i<N){
        int s = X[i++];
        while(i<N && X[i] <= s + R) i++;
        int p = X[i-1];
        while(i<N && X[i] <= p + R) i++;
        ans++;
    }
    printf("%d\n",ans);
}
int main(){
    while(true){
        cin >> R >> N;
        if (N < 0 && R < 0){
            break;
        }
        for(int i=0;i<N;i++){
            cin >> X[i];
        }
        solve();
    }
    return 0;
}
