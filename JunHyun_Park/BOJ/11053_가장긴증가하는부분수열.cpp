#include <cstdio>   // 11053_가장긴증가하는부분수열 [DP]
#define max(x,y) x>y ? x:y;

int n, z, dp[1001], A[1001];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
		dp[i]=1;
		for(int j=0; j < i; j++)
			if(A[j] < A[i] && dp[j]+1 > dp[i])
				dp[i] = dp[j]+1;
		z = max(z, dp[i]);
    }
    printf("%d", z);
    return 0;
}