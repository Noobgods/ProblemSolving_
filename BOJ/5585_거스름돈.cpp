#include <cstdio>	// 5585_거스름돈 [그리디]
int m[5] = {500, 100, 50, 10, 5};
int main(){
	int n,j,x;
	scanf("%d",&n);
	for(n=1000-n,x=0,j=0;n>4;j++)
		if(n>=m[j]){n-=m[j--];x++;}
	printf("%d",x+n);
	return 0;
}