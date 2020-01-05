#include<cstdio>    // 2292_벌집 [규칙]
long long int n;
int s;
int six(int x){
	if(n <= 0) return 1;
	n -= 6*x;
	return six(x+1) + 1;
}
int main() {
	scanf("%lld", &n);
	n -= 1;
	printf("%d", six(1));
}