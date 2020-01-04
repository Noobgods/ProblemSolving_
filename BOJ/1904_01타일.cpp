#include<cstdio>	// 1904_01타일 [DP], [수학]
#define MOD 15746
int N;
int R[3];
int main(){
	scanf("%d", &N);
	R[1] = 1;
	R[2] = 2;
	for(int i=3; i<=N; i++){
		R[i%3] = (R[(i-1)%3] + R[(i-2)%3])%MOD;
	}
	printf("%d", R[N%3]);
	return 0;
}
