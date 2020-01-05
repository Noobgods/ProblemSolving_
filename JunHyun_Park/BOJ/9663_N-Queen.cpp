#include<cstdio>    // 9663_N-Queen [백트래킹]
int cnt, n;
bool p[17][17]= {false};
bool isPos(int x, int y){
	int d=0;
	for(int i=x-1; i>=0; i--){
		d++;
		if(p[i][y] || (0<=y-d && p[i][y-d]) || (n>y+d && p[i][y+d])) return false;
	}
	return true;
}
int f(int x){
	if(x == n) {
		return 1;
	}
	int c=0;
	for(int i=0; i<n; i++){
		if(isPos(x, i)){
			p[x][i] = true;
			c += f(x+1);
			p[x][i] = false;
		}
	}
	return c;
}
int main(){
	scanf("%d", &n);
	printf("%d", f(0));
	return 0;
}