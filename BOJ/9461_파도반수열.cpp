#include<cstdio>	// 9461_파도반 수열 [DP]
int N, T;
long long int R[101]={0,1,1,1,2,2};
int main(){
	scanf("%d", &T);
	for(int i=6; i<=100; i++)
		R[i] = R[i-1] + R[i-5];
	while(T--){
		scanf("%d", &N);
		printf("%lld\n", R[N]);
	}
	return 0;
}
