#include<cstdio>    // 12841_정보대등산 [탐색]
long long int r[100001], c[100001];
int main() {
	int n, i, min;
	scanf("%d", &n);
	for (i = 0; i < n; i++)  scanf("%lld", &c[i]);
	for (i = 1; i < n; i++)  scanf("%lld", &r[i]);
	for (i = 2; i <= n; i++){
        if(i!=n) r[i] += r[i - 1];
		c[i-1] += r[i-1];
		scanf("%lld", &r[i - 1]);
    }
	for (min = n,i = n - 1; i > 0; i--) {
        if(i > 1) r[i - 1] += r[i];
		c[i-1] += r[i];
		if (c[min-1] >= c[i-1]) min = i;
	}
	printf("%d %lld", min, c[min-1]);
	return 0;
}