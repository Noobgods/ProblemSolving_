#include<cstdio>    // 5430_AC [문자열처리], [덱], [규칙]
#include<iostream>
#include<string.h>
using namespace std;
int T;
int main() {
	scanf("%d", &T);
	while (T--) {
		bool error = false;
		char c = 0, s[300000];
		int del[2] = { 0,0 }, r = 0, n = 0, x[100000];
		cin.ignore();
		do {
			c = getchar();
			if (c == 'R')
				r = (r + 1) % 2;
			if (c == 'D')
				del[r] ++;
		} while (c != 10);
		scanf("%d %s", &n, s);

		if ((del[0] + del[1]) > n) { printf("error\n"); continue; }
		else {
			char *d = strtok(s, "[],");
			for (int i = 0; d != NULL && i < n; i++) {
				x[i] = atoi(d);
				d = strtok(NULL, "[],");
			}
		}

		printf("[");
		if (r == 0)
			for (int i = 0; i < n - del[1]; i++)
				if (del[0] <= i) {
					printf("%d", x[i]);
					if (i + 1 < n - del[1])
						printf(",");
				}
		if (r == 1)
			for (int i = n - 1; i >= del[0]; i--)
				if (n - del[1] > i) {
					printf("%d", x[i]);
					if (i > del[0])
						printf(",");
				}
		printf("]\n");
	}
	return 0;
}