#include <stdio.h>
#define MAX_N 1000

void insertsort(int * sumscores,int* rank,int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = sumscores[i];
        j = i - 1;
        while(j >= 0 && sumscores[j] < key){
            sumscores[j+1]=sumscores[j];
            rank[j+1] = rank[j];
            j -= 1;
        }
        sumscores[j+1] = key;
        rank[j+1] = i;
    }
}
void merge(int * sumscores,int * rank,int start,int mid,int end){
    int tmp1[MAX_N+1] = {0};
    int tmp2[MAX_N+1] = {0};
    int tmp3[MAX_N];

    int tmpindex = start;
    int leftindex = start;
    int rightindex = mid + 1;
    
    int i;
    for(i=start; i <= mid ; i++){
        tmp1[i] = sumscores[i];
    }
    tmp1[mid+1] = -1; //

    for(i=mid+1;i<=end;i++){
        tmp2[i] = sumscores[i];
    }
    tmp2[end+1] = -1;
    for(i=start; i<=end; i++){
        tmp3[i]=rank[i];
    }

    while(tmpindex <= end){
        if(tmp1[leftindex] < tmp2[rightindex]){
            rank[tmpindex] = tmp3[rightindex];
            sumscores[tmpindex++] = tmp2[rightindex++];
        }else{
            rank[tmpindex] = tmp3[leftindex];
            sumscores[tmpindex++] = tmp1[leftindex++];
        }
    }
}
void mergesort(int* sumscores,int * rank,int start, int end){
    if(start < end){
        int mid = (start + end) /2;
        mergesort(sumscores,rank,start,mid);
        mergesort(sumscores,rank,mid+1,end);
        merge(sumscores,rank,start,mid,end);
    }
}
int main(){
    int sumscores[MAX_N] = {0};
    int rank[MAX_N] = {0};
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        int e,g,m,h;
        scanf("%d %d %d %d",&e,&g,&m,&h);
        sumscores[i] = e + g + m + h;
        rank[i] = i;
    }
    //for(i=0;i<n;i++){
      //printf("%d %d\n",rank[i],sumscores[i]);
    //}

    insertsort(sumscores,rank,n);
    //mergesort(sumscores,rank,0,n-1);
    //for(i=0;i<n;i++){
      //printf("%d %d\n",rank[i],sumscores[i]);
    //}

    for (i=0; i < n; i++){
        if(rank[i] == 0){
            break;
        }
    }
    printf("%d\n",i+1);
    return 0;
}

