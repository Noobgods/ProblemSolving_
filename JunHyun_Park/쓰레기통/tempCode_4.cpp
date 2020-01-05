#include<cstdio>    // 12842_¨¡?¡¾?¨ù?¨¬¢¬¡¤? [¡¾¢¬??]
int n, s, m, i, me[100000][2], es;
int main() {
	scanf("%d %d %d ", &n, &s, &m);

	for (i = 0; i < m; i++) {
		scanf("%d", &me[i][0]);
		me[i][1] = me[i][0];
	}

	for (es = 0; es < n - s;) {
		for (i = 0; i < m;) {
			if (me[i][0] == me[i][1]) {
				es++;
				me[i][1] = 0;
			}
			else me[i++][1]++;
			if (es >= n - s) break;
		}
	}
	printf("%d", i + 1);
	return 0;
}