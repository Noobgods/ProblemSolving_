#include <cstdio>   // 1463_1로만들기 [DP]
int n, *r;
int min(int x, int y) { return x < y ? x : y; }
int cal(int n) {
	if (n == 1) return 0;
	if (r[n] > 0) return r[n];
	
	r[n] = cal(n - 1)+1;
	if (n % 2 == 0) {
		int t = cal(n / 2)+1;
		r[n] = min(t, r[n]);
	}
	if (n % 3 == 0) {
		int t = cal(n / 3)+1;
		r[n] = min(t, r[n]);
	}
	return r[n];
}
int main() {
	scanf("%d", &n);
	r = new int[n+1];
	printf("%d", cal(n));
	return 0;
}