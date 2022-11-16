#include<cstdio>    // 2446_별찍기 [구현]
int N;
int main(){
    scanf("%d", &N);
    for(int i=1; i<N*2; i++){
        if(i<=N)
        for(int j=1; j<N*2-i+1; j++){
            if(i<=j) printf("*");
            else printf(" ");
        }
        else 
        for(int j=1; j<i+1; j++){
            if((N*2-1)-i<j) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}