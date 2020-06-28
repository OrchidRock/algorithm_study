#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

#define MAX_N 50005
struct node{
    int start,end,pos;
}cows[MAX_N];

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

int stallcount = 0;
int assignment[MAX_N];
int N;

bool cmp(node a,node b){
    if(a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

int main(){
    scanf("%d",&N);
    for(int i=0 ; i < N;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        cows[i].start = a;
        cows[i].end = b;
        cows[i].pos = i;
    }
    sort(cows,cows+N,cmp);
    stallcount = 1;
    //stalls[1].first = 0;
    //stalls[1].second = 0;
    q.push(pair<int,int>(cows[0].end,1));
    assignment[cows[0].pos] = 1;
    /* 
    for(int i=0 ; i < N;i++){
        printf("%d %d %d\n",cows[i].start,cows[i].end,cows[i].pos);
    }*/

    for(int i=1 ; i < N;i++){
        pair<int,int> now = q.top();
        //printf("%d %d\n",now.first,now.second);
        int j;
        if(cows[i].start > now.first){ // same stall
            j = now.second;
            q.pop();
        }else{ // new stall;
            stallcount+=1;
            j = stallcount;
        }
        assignment[cows[i].pos] = j;
        q.push(pair<int,int>(cows[i].end,j));
    }
    printf("%d\n",stallcount);
    for(int i=0;i<N;i++){
        printf("%d\n",assignment[i]);
    }
    return 0;
}
