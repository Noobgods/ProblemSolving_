#include<cstdio>    // 11722_가장긴감소부분수열 [DP]
#define max(x,y) x>y?x:y

int N, A[1001], M, dp[1001], idx;
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
        scanf("%d",&A[i]);

    for(int i=N-1; i>=0; i--){
        idx=0;
        for(int j=N-1; j>=i; j--){
            if(A[i] > A[j]){
                idx = max(idx, dp[j]);
            }
        }
        dp[i] = idx+1;
    }
    for(int i=0; i<N; i++)
        M = max(M, dp[i]);
    printf("%d", M);
	return 0;
}