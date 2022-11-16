#include <cstdio>   // 1789_수들의합 [수학]
#include <math.h>
long long int s;
int main(){
	scanf("%lld", &s);
	printf("%d", (int)((sqrt(8*s+1)-1.0f)/2));
	return 0;
}