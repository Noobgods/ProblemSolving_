#include <cstdio>   // 4673_셀프넘버 [수학], [에라토스테네스의체]

bool num[10001];
void selfnum(int i) {
	if (i > 10000) return;
	int s;
	s = i + (i / 1000) + (i%1000)/100 + (i%100)/10 + i % 10;
	if (!num[s]&& s<10000)
		num[s] = true;
	selfnum(s);
}
int main() {
	for (int i = 1; i < 10000; ++i)
		selfnum(i);
	
	for (int i = 1; i < 10000; ++i) 
		if (!num[i])
			printf("%d\n", i);
	

	return 0;
}