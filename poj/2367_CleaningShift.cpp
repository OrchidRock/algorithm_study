#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int,int> > cows;
int N,T;
int ans = 0;
void solve(int index){
    if(cows[index].second >= T) return;
    int nextindex = -1;
    int m = cows[index].second;
    for(int i=index+1;i<N;i++){
        if(cows[i].first > cows[index].second) break;
        if(cows[i].second > m){
            m = cows[i].second;
            nextindex = i;
        }
    }
    if(nextindex < 0) ans = -1;
    else{
        ans ++;
        solve(nextindex);
    }
}

int main(){
    scanf("%d %d",&N,&T);
    for(int i=0; i < N;i++) {
        int s,f;
        scanf("%d %d",&s,&f);
        pair<int,int> p;
        p.first = s;
        p.second = f;
        cows.push_back(p);
    }
    sort(cows.begin(),cows.begin()+N);
    /*for(int i = 0;i<N;i++){
        printf("%d %d\n",cows[i].first,cows[i].second);
    }*/

    if(cows[0].first == 1){
        ans += 1;
        solve(0);
    }
    printf("%d\n",ans);
    return 0;
}
