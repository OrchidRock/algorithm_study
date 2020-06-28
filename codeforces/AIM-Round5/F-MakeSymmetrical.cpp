#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define LIMIT 200005
int main(){
    int q;
    cin >> q;
    vector<pair<int,int>> s;
    vector<pair<int,int>>::iterator it;
    for(int i=0; i < q; i++){
        int t,x,y;
        cin >> t >> x >> y;
        if(t == 1){
            s.push_back(pair(x,y));    
        }else if(t == 2){
            for(it=s.begin();it!=s.end();it++){
                if(*it.first == x && *it.second == y){
                    s.erase(it);
                    break;
                }
            } 
        }else{
            int ans = 0;
            for(it=s.begin();it!=s.end();it++){
                if(((float)(*it.first * y)/(float)x) == (float)(*it.second)){
                    continue;
                }
            }
        }
    }
    return 0;
}
