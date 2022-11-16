#include<cstdio>	// 14753 MultiMax [Ģ]
int m[4], rm[4] = { -1001, -1001, -1001}, lm[4] = {-1001, -1001, -1001}, c;
int max(int x, int y) { return x>y?x:y;}
int main(){
	for(scanf("%d", &c); c--;){
		int n;
		scanf("%d", &n);
		for(int i=2; i>=0; i--){
			if(n >= rm[i]) {
				rm[i+1] = rm[i];
				rm[i] = n;
			}
			if(-n >= lm[i]) {
				lm[i+1] = lm[i];
				lm[i] = -n;
			}
		}
	}
	m[0] = rm[0]*rm[1]*rm[2];
	m[1] = lm[0]*lm[1]*rm[0];
	m[2] = rm[0]*rm[1];
	m[3] = lm[0]*lm[1];
	
	printf("%d", max(m[0], max(m[1], max(m[2], m[3]))));

	return 0;
}