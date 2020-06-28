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
    
    int a_0_count = 0;
    int sum_0_count = 0;
    int sum_1_count = 0;
    int sum_2_count = 0;
    int i,sum;
    for(i=0; i< n; i++){
        if(a[i] == '0'){
            a_0_count ++;
        }
        sum = a[i]-'0' + (b[i]-'0');
        if(sum == 2){
            sum_2_count ++;    
        }else if(sum == 0){
            sum_0_count ++;
        }else{
            sum_1_count ++;
        }
    } 
    int sum_01_count = sum_1_count + sum_0_count;
    int count = (sum_01_count * (sum_01_count-1))/2 + (sum_2_count * sum_0_count) - (a_0_count * (a_0_count-1))/2;
    printf("%d\n",count);
    return 0;
}
