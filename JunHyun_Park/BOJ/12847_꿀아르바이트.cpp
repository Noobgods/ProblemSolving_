#include<cstdio>	// 12847_꿀아르바이트 [규칙]
int main(){
	int n,m,w[100001];
	long long s=0, a;
	scanf("%d %d",&n, &m);
	for(int i=0; i<n; i++)
		scanf("%d",&w[i]);
	for(int i=0; i<m; i++) s+=w[i];
	a = s;
	for(int i=0; i<n-m; i++){
		s -= w[i] - w[m+i];
		if(a < s) a= s;
	}
	printf("%lld", a);
	return 0;
}