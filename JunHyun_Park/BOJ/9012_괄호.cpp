#include<cstdio>    // 9012_괄호 [스택]
#include<cstring>
using namespace std;

int main() {
	int cnt, n;
	char c[50];

	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		cnt = 0;

		scanf("%s", &c);

		for (int j = 0; j < strlen(c); j++) {
			if (c[j] == '\n')
				break;
			if (c[j] == '(')
				cnt++;
			else if (c[j] == ')' && cnt > 0)
				cnt--;
			else if (c[j] == ')' && cnt <= 0) {
				cnt--;
				break;
			}
		}	
		if(cnt == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}