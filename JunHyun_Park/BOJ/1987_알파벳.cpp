#include<cstdio>	// 1987_알파벳 [백트래킹]
int R, C, max = 0;
char s[21][21];
bool ba[91];
void f(int x, int y, int n) {
	if (n > max) max = n;
	for (int i = 0; i < 4; i++) {
		if (i == 0 && x + 1 < R && !ba[s[x + 1][y]]) {
			ba[s[x + 1][y]] = true;
			f(x + 1, y, n + 1);
			ba[s[x + 1][y]] = false;
		}
		if (i == 1 && x - 1 >= 0 && !ba[s[x - 1][y]]) {
			ba[s[x - 1][y]] = true;
			f(x - 1, y, n + 1);
			ba[s[x - 1][y]] = false;
		}
		if (i == 2 && y + 1 < C && !ba[s[x][y + 1]]) {
			ba[s[x][y + 1]] = true;
			f(x, y + 1, n + 1);
			ba[s[x][y + 1]] = false;
		}
		if (i == 3 && y - 1 >= 0 && !ba[s[x][y - 1]]) {
			ba[s[x][y - 1]] = true;
			f(x, y - 1, n + 1);
			ba[s[x][y - 1]] = false;
		}
	}
}
int main() {
	scanf("%d %d\n", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", s[i]);
	}
	ba[s[0][0]] = true;
	f(0, 0, 1);
	printf("%d", max);
	return 0;
}