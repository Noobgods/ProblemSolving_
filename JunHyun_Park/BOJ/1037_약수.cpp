#include<cstdio>    // 1037_ []

int A,N, min=1000000000, max=0;
int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&A);
        if(min > A) min = A;
        if(max < A) max = A;
    }
    printf("%d", max*min);
    return 0;
}