#include <cstdio>

int main(){
	int x1, x2, n, y1, y2, startX;
	scanf("%d %d %d %d %d", &n, &x1, &x2, &y1, &y2);
	for(int i= 0; i<n; i++){
		int a = i + ((x2- x1)*i) +x1, 
		b = a + (x2- x1);
		printf(",%d, %d, %d, %d)\n", a, y1, b, y2);
	}

	return 0;
}
