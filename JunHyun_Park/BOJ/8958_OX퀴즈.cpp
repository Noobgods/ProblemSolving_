#include <cstdio>   // 8958 OX [구현]
int N, a, s;;
int main() {
	char c;
	scanf("%d ", &N);
	while (N) {
		a = 1, s = 0;
		do{
			c = getchar();
			if (c == 'O') s += a++;
			else if( c == 'X' ) a = 1;
		} while (c != 10);
		printf("%d\n", s);
		N--;
	}
	return 0;
}