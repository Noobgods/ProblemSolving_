#include<cstdio>	// 14888_연산자끼워넣기 [브루트포스], [백트래킹]
#include<limits.h>
int op[4] ,N;
int	num[11];
int smax = INT_MIN;
int smin = INT_MAX;
void f(int n, int sum, int A, int S, int M, int D){
	if(n>=N) {
		if(smax < sum) 	smax = sum;
		if(smin > sum) 	smin = sum;
		return;
	}
	for(int i=0; i<4; i++){
		if(i == 0 && A < op[0])	f(n+1, sum+num[n], A+1, S, M, D);
		if(i == 1 && S < op[1])	f(n+1, sum-num[n], A, S+1, M, D);
		if(i == 2 && M < op[2])	f(n+1, sum*num[n], A, S, M+1, D);
		if(i == 3 && D < op[3])	f(n+1, sum/num[n], A, S, M, D+1);
	}
}
int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &num[i]);
	scanf("%d %d %d %d", &op[0], &op[1], &op[2], &op[3]);
	f(1, num[0], 0, 0, 0,0);
	printf("%d\n%d", smax, smin);
	return 0;
}