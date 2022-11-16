#include<cstdio>	// 2748_이친수 [DP]
int N;
long long int R[100][2]={{1,1}};
long long int pinary(int n, int r){
	if(n == 1) return 1;
	if(R[n][r] != 0) return R[n][r];
	if(r == 1) R[n][r] = pinary(n-1, 0);
	if(r == 0) R[n][r] = pinary(n-1, 0) + pinary(n-1, 1);
	return R[n][r];
}
int main(){
	scanf("%d", &N);
	
	printf("%lld", pinary(N, 1));
	return 0;
}