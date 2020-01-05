#include <cstdio>   // 1094_막대기 [수학], [시뮬레이션]
int x, n, i=64;
int main(){
	scanf("%d", &x);

	while(i>0){
		if((x - i) >= 0){
			n++;
			if((x - i) == 0) break;
			x -= i;
		}
		i/=2;
	}
	printf("%d", n);
	return 0;
}