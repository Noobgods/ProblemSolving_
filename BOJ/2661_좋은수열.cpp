
#include<cstdio>	// 2661_좋은수열 [백트래킹]
#include<string.h>
#include<iostream>
using namespace std;
int N;
char s[81];
bool check(int n) {
	for (int j = 2; j <= (n + 1) / 2; j++) {
		char temp[81];
		memcpy(temp, s,	n-j+1);
		temp[n - j+2] = '\0';
		if (strstr(temp, &s[n - j + 1]) != NULL)
			return false;
	}
	return true;
}
void f(int n) {
	if (n == N) {
		printf("%s", s);
		exit(0);
	}
	for (int i = 0; i < 3; i++) {
		if (s[n - 1] != '1'+i || n==0) {
			s[n] = '1' + i;
			s[n + 1] = '\0';
			if (check(n))
				f(n + 1);
		}
	}
}
int main() {
	scanf("%d", &N);
	f(0);
	return 0;
}