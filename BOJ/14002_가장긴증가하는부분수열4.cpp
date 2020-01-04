#include <cstdio>   // 14002_가장긴증가하는부분수열4.cpp

int n, z, dp[1001], A[1001],list[1001];
void print(int x){
    if(x<=0) return;
    print(list[x]);
    printf("%d ", A[x]);
}
int main() {
    scanf("%d", &n);
    int k=0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
		dp[i]=1;
		for(int j=1; j <= i; j++)
			if(A[j] < A[i] && dp[j]+1 > dp[i]){
				dp[i] = dp[j]+1;
                list[i] = j;
            }
        if(dp[z] < dp[i])
            k = z = i;
    }
    printf("%d\n", dp[z]);
    print(k);
    return 0;
}
