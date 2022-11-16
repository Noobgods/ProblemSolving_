#include<cstdio>    // 11401_이항계수3 [수학]
#define MOD 1000000007

long long pwr(long long p, long long r){
	long long ans = 1;
	while ( r > 0){
		if (r%2 != 0)
			ans = (ans * p) % MOD;
		p = (p*p) %MOD;
		r /= 2;
	}
	return ans;
}

int main(){
	int n, r;
	long long int fac_A, fac_B, fac_C, i;
	scanf("%d %d", &n, &r);

	fac_A = fac_B = fac_C = 1;
	for(i=2; i<=n; i++){
		fac_A = (fac_A * i) % MOD;
		if (i==r) fac_B = fac_A;
		if (i==n-r) fac_C = fac_A;
	}
	fac_C = (fac_B * fac_C) % MOD;
	fac_B = pwr(fac_C, MOD-2) % MOD;
	fac_A = (fac_A * fac_B) % MOD;
	printf("%llu", fac_A);
	return 0;
}