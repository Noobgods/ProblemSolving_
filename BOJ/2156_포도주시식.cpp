#include <cstdio>      // 2156_포도주시식 [DP]
#define max(x,y) x>y?x:y
int N, dp[10001], A[10001];
int main() {
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    dp[0] = A[0];
    if(N > 1) dp[1] = A[0] + A[1];
    
    if(N > 2) {
        dp[2] = max(A[0] + A[2], A[0] + A[1]);
        dp[2] = max(dp[2], A[1] + A[2]);
    }
    for(int i=3; i<N; i++){
        dp[i] = max(dp[i-2] + A[i], dp[i-3] + A[i-1] + A[i]);
        dp[i] = max(dp[i],dp[i-1]);
        dp[i] = max(dp[i],dp[i-2]);
        if(i > 3)
            dp[i] = max(dp[i], dp[i-4]+A[i-1]+A[i]);
    }
    N--;
    dp[N] = max(dp[N-3] + A[N-1] + A[N], dp[N]);
    printf("%d\n\n", dp[N]);
    return 0;
}

