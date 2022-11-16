#include <cstdio>	// 2579 계단오르기 [DP]
int n, s[301], dp[301];
int max(int x, int y){
	return x>y?x:y;
}
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &s[i]);

	dp[0] = s[0];
	dp[1] = max(s[0] + s[1], s[1]);
	dp[2] = max(s[0] + s[2], s[1] + s[2]);
	for(int i=3; i<n; i++)
		dp[i] = max(dp[i-3] + s[i-1] + s[i], dp[i-2] + s[i]);
	
	printf("%d\n",dp[n-1]);
	return 0;
}