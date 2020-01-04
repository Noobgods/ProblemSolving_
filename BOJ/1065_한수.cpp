#include <cstdio>   // 1065_한수 [브루트포스], [탐색]
int N, s;
int seq(int a) {
	int q[3];
	q[0] = a % 10;
	q[1] = (a % 100) / 10;
	q[2] = a / 100;
	if ((q[1] - q[0]) == (q[2] - q[1])) return 1;
	else return 0;
}
int main() {
	scanf("%d", &N);
	if (N >= 100) {
		s = 99;
		for (int i = 100; i <= N; ++i)
			s += seq(i);
	}
	else s = N;
	printf("%d", s);
	return 0;
}