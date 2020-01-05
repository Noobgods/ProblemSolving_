#include <cstdio>   // 1654_랜선자르기 [이분탐색]
int k, n; unsigned long long nA[10001];
int main(){
	unsigned long long max = 0;
	unsigned long long result =0;
	scanf("%d %d", &k, &n);
	for(int i=0; i<k; ++i){
		scanf("%lld", &nA[i]);
		if (nA[i] > max) max = nA[i];
	}
	unsigned long long mid = max;
	unsigned long long l = 0, r = mid;
	while(l <= r){
		int z=0;
		for(int i=0; i<k; ++i)
			z += nA[i]/mid;
		if(z >= n) {
			l = mid+1;
			if(mid > result)	
				result = mid;
		}
		else if(z < n)
			r = mid-1;
			
		mid = (l+r)/2;
	}

	printf("%lld", result);
	return 0;
}