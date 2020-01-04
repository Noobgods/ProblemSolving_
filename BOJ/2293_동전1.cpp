#include<cstdio>    // 2293_동전1 [DP]

int N, K, A[101], DP[2][10001];
int main(){
    scanf("%d %d",&N, &K);
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);

    DP[0][0] = 1;
    for(int i=1;i<=N;i++){
        for(int j=0; j<=K; j++){
            if(j < A[i-1])  
                DP[i%2][j] = DP[(i-1)%2][j];
            else
                DP[i%2][j] = DP[i%2][j-A[i-1]] + DP[(i-1)%2][j];
        }
    }
    printf("%d", DP[N%2][K]);

	return 0;
}