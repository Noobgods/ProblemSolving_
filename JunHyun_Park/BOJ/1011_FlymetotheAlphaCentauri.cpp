#include<cstdio>    // 1011_FlymetotheAlphaCentauri [±ÔÄ¢]
int main() {
	int N;
	scanf("%d", &N);
	while(N>0){
		int count = 2;
		int length = 2;
		unsigned int x, y;

		scanf("%d %d", &x, &y);
	
		unsigned int s = y - x;
		unsigned int l = 2;
		bool d = false;
		while(s>l){
			l += count;
			if(d) count++;
			d = !d;
			length ++;
		}
		
		if (s <= 1)			printf("1\n");
		else if (s == 2)	printf("2\n");
		else 				printf("%d\n", length);
		N--;
	}
	return 0;

}