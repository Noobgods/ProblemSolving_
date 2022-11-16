#include<cstdio>    // 10815_숫자카드 [이분탐색]
#include<algorithm>
using namespace std;

int M[500000], N[500000];

int Search(int k, int n) {
	int low = 0, high = n - 1, m;
	while (low <= high) {
		m = (low + high) / 2;
		if (M[m] == k)
			return 1;
		else if (M[m] > k)
			high = m - 1;
		else low = m + 1;
	}
	return 0;
}
int main() {
	int m, n, i;

	scanf("%d", &m);
	for(i = 0; i < m; scanf("%d", &M[i++]));

	scanf("%d", &n);
	for (i = 0; i < n; scanf("%d", &N[i++]));

	sort(M, M + m);
	for (i = 0; i < n; i++)
		printf("%d ", Search(N[i], m));

	return 0;
}