#include <cstdio>
#include <iostream>

using namespace std;
#define MAX_N 2005

int N;
char S[MAX_N];

void solve(){
    int a = 0;
    int b = N-1;
    int count = 0;
    while(a<=b){
        bool left = false;
        for (int i=0; a+i <=b;i++){
            if(S[a+i] < S[b-i]){
                left = true;
                break;
            }else if(S[a+i] > S[b-i]){
                left = false;
                break;
            }
        }
        count += 1;
        if(left) putchar(S[a++]);
        else putchar(S[b--]);
        if(count == 80){
            putchar('\n');
            count = 0;
        }
    }
    putchar('\n');
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin >> S[i];
    }
    solve(); 
    return 0;
}

