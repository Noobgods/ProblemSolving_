#include<cstdio>    // 14501 퇴사 [DP]
#define max(x,y) x>y?x:y
int DP[1001], A[2], N, M;
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &A[0], &A[1]);
        if(DP[i]< DP[i-1]) DP[i]= DP[i-1];
        if(i+A[0] <= N)
            DP[i+A[0]] = max(DP[i+A[0]] , DP[i]+A[1]);
    }

    for(int i=0; i<=N; i++)
        M = max(M, DP[i]);
    printf("%d", DP[N]);
    return 0;
}