#include<cstdio>    // 10799_쇠막대기 [스택]
#include<cstring>
using namespace std;

int main() {
	char s[100001];
	int n = 0, z = 0;
	scanf("%s", s);

	for (int i = 0; i<strlen(s); i++) {
		if (s[i] == '(' && s[i + 1] == ')') {
			z += n;
			i++;
		}
		else if (s[i] == '(') {
			n++;
			z++;
		}
		else if (s[i] == ')') {
			n--;
		}
	}
	printf("%d", z);
	return 0;
}