#include<cstdio>    // 11052_카드구매하기 [DP]
#define max(a,b) (a>b?a:b)
using namespace std;

int n, p[1000], r[1000];

int main() {
	 scanf("%d", &n);

	for (int q, j = 1; j <= n; j++) {
		scanf("%d", &p[j]);
		q = 0;
		for (int i = 1; i <= j; i++)
			q = max(q, p[i] + r[j - i]);
		r[j] = q;
	}
	printf("%d", r[n]);

	return 0;
}