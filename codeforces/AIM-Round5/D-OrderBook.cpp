#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int PRICE_LIMIT = 1e9;
int main(){
    set<int> orders;
    set<int>::iterator it;
    int bestBuy = 0;
    int bestSell = PRICE_LIMIT;
    orders.insert(PRICE_LIMIT);
    orders.insert(0);
    int ans = 1;
    int n;
    cin >> n;
    string action;
    int price = 0;
    ll res = 1;
    for(int i=0; i<n;i++){
        cin >> action >> price;
        if(action[1] == 'D'){
            if(price <= bestSell  && price >= bestBuy){
                res ++;
            }
            orders.insert(price);
        }else{
            res = 1;
            if(price < bestBuy || price > bestSell){
                ans = 0;
                break;
            }
            orders.erase(price);
            if(price > bestBuy && price < bestSell){
                ans = (ans * 2) % MOD;
            }
            it = orders.lower_bound(price);
            bestSell = *(it);
            bestBuy = *(--it);
        }      
    }
    cout << ans * res % MOD << endl;
    return 0;
}
