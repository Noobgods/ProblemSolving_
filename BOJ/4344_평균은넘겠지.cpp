#include <cstdio>   // 4344_평균은넘겠지 [수학]
int n, x;
int main() {
    scanf("%d", &n);
	while(n--){
		int sum = 0;
		int a[1000];
		double avg =0;
		scanf("%d",&x);

		for(int i=0; i<x; ++i){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		avg = (double)sum / x;
		int count = 0;
		for(int i=0; i<x; ++i)
			if(a[i] > avg) count++;
		printf("%.3f%%\n", (double)count * 100.0 / x);
	}
    return 0;
}