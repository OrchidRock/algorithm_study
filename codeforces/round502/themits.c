#include <stdio.h>
#define MAX_LEN 100000+5

int main(){
    int n;
    char a[MAX_LEN];
    char b[MAX_LEN];
    
    scanf("%d",&n);
    getchar();
    fgets(a,MAX_LEN,stdin);
    fgets(b,MAX_LEN,stdin);
    
    int i,j;
    int count = 0;
    //printf("n=%d\n",n);
    for(i=0; i< n ; i++){
        for(j=i+1; j < n ; j++){
            if(b[i] != b[j] || (b[i]=='0' && b[j] == '0')){
                if(a[i]!=a[j]){
                    count ++;
                }
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
