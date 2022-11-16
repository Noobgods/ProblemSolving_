#include<cstdio>	// 1834 나머지와몫이같은수 [수학] 
int main(){
	int n;
	unsigned long long int s=0;
	scanf("%d", &n);
	for(int i=1; i<n; i++){
		s += (n*i)+i;
	}
	printf("%llu",s);
	return 0;
}