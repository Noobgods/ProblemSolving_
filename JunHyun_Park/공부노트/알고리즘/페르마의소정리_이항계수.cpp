#include<cstdio>
#define MOD 2147483647
long long fac[4000001], facinv[4000001];

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
long long comb(long long n, long long r){
	long long ans = (fac[n] * facinv[r]) %MOD;
	ans = (ans * facinv[n-r]) %MOD;
	return ans;
}
int main(){
	int n, r;
	scanf("%d %d", &n, &r);

	fac[1] = fac[0] = facinv[1]= facinv[1]= 1;
	for(int i=2; i<=n; i++){
		fac[i]= fac[i-1] * i;
		facinv[i] = pwr(fac[i], MOD-2);
	}
	printf("%llu", comb(n, r));
	return 0;
}