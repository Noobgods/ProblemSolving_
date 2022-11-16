#include<cstdio>    // 11054_가장긴바이토닉부분수열 [DP]
#define max(x,y) x>y?x:y

int N, A[1001], M, dp[1001][2], idx;
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
        scanf("%d",&A[i]);

    for(int i=0; i<N; i++){
        idx = 0;
        for(int j=0; j<i; j++){
            if(A[i] > A[j]){
                idx = max(idx, dp[j][0]);
            }
        }
        dp[i][0] = idx + 1;
    }
    for(int i=N-1; i>=0; i--){
        idx=0;
        for(int j=N-1; j>=i; j--){
            if(A[i]> A[j]){
                idx = max(idx, dp[j][1]);
            }
        }
        dp[i][1] = idx + 1;
    }
    for(int i=0; i<N; i++)
        M = max(M, dp[i][0]+dp[i][1]);
    printf("%d", M-1);
	return 0;
}