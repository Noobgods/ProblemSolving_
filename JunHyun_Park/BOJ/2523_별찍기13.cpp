#include<cstdio>    // 2523_별찍기13
int N;
int main(){
    scanf("%d", &N);
    for(int i=1; i<N*2; i++){
        if(i<=N)
        for(int j=1; j<=i; j++){
            printf("*");
        }
        else 
        for(int j=N*2; j>i; j--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}