#include <cstdio>   // 1193_분수찾기 [수학], [규칙]
#include <math.h>
int s;
int main(){
	int n, z, x, t, d;
	scanf("%d", &s);
	s -= 1;
	n = (int)((sqrt(8*s+1)-1.0f)/2);
	z = (n*(n + 1))/2;
	x = s - z;
	if(n%2 == 1) {
		t = 1 + x;
		d = 1 + n - x;
	}
	if(n%2 == 0){
		t = 1 + n - x;
		d = 1 + x;
	}
	printf("%d/%d", t, d);
	return 0;
}