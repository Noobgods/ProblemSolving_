#include<cstdio>	// 1759_암호만들기 [백트래킹]
#include<algorithm>
using namespace std;
int L,C;char s[50], cs[20]="aaaaaaaaaaaaaaa\0";bool ba[18];
void f(int x, int y, int m, int j) {
	if (x==L) {if (m >= 1 && j >= 2) printf("%s\n", cs);}
	else for(int i=y;i<C;i++) if(!ba[i]) {
		ba[i] = true;
		cs[x] = s[i];
		if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') f(x+1,i+1,m+1,j);
		else f(x+1,i+1,m,j+1);
		ba[i] = false;
	}
}
int main() {
	scanf("%d %d\n", &L, &C);
	for (int i = 0; i < C;) {
		s[i] = getchar();
		if (s[i] != ' ') i++;
	}
	sort(&s[0], &s[C]);
	cs[L] = 0;
	f(0,0,0,0);
	return 0;
}