#include<cstdio>	// 2231_분해합 [브루트포스]
#define p(x,y) x>=y?x-100:0
int main(){
	int N, i, s=0;
	scanf("%d", &N);
	for(i=p(N,200); i<N&&s!=N;){
		s = ++i;
		for(int j=1; N%j != N; j*=10)
			s += (i%(j*10))/j;
	}
	if(i == N) i=0;
	printf("%d", i);
	return 0;
}