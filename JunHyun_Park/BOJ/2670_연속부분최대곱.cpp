#include<cstdio>	// 2670_연속부분최대곱 [DP]
#include<math.h>
int N;
double A[10000], DP[10000];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N; i++){
		scanf("%lf", &A[i]);
	}

	DP[0] = A[0];
	for(int i=1; i<N; i++){
		if(DP[i-1]*A[i] > A[i])
			DP[i] = DP[i-1]*A[i];
		else
			DP[i] = A[i];
	}
	int idx = 0; 
	for(int i=1; i<N; i++)
		if(DP[idx] < DP[i]) idx = i;
	printf("%.3lf", round(DP[idx]*1000)/1000);
	return 0;
}