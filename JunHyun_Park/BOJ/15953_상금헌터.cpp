#include<cstdio>    // 15953_상금헌터 [구현]
int main() {
	int N, one, two,
	O[7] ={0, 5000000, 3000000, 2000000, 500000, 300000, 100000},
	T[6] ={0, 5120000, 2560000, 1280000, 640000, 320000};
	scanf("%d", &N);
	while(N>0){
		scanf("%d %d", &one, &two);
		int o_t=1;
		while(one > 0)
			one -= o_t++;
		int t_t=1, t_tt=1;
		while(two > 0){
			two -= t_t;
			t_t *= 2;
			t_tt++;
		}
		if(o_t-1 > 6) o_t = 1;
		if(t_tt-1 > 5) t_tt = 1;
		printf("%d\n", O[o_t-1] + T[t_tt-1]);
		N--;
	}
	return 0;
}