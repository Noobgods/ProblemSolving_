#include<cstdio>	// 1799_비숍 [백트래킹]
bool visited[11][11];
bool chess[11][11];
int w_max =0, b_max =0, N, M;
bool check(int x, int y){
	int d=0;
	for(int i=x-1; i>=0; i--){
		d++;
		if((visited[i][y-d] && y-d >= 0) || (visited[i][y+d] && y+d < N)) return false;
	}
	return true;
}
void f(int r, int n){
	if(r>=M) {
		if(r%2 == 0 && n > b_max){
			
			b_max = n;
		}
		if(r%2 == 1 && n > w_max){
			w_max = n;
		}
		return;
	}
	for(int i=r;; i+=2){
		if(i >= M) {f(i+2, n); break;}
		if(N%2 ==0){
			if(i!= 0 && i%N==0) i++;
			else if(i!= 1 && i%N==1) i--;
		}
		int x = i/N, y = i%N;
		if(!visited[x][y] && chess[x][y] && check(x,y)){
			visited[x][y] = true;
			f(i+2, n+1);
			visited[x][y] = false;
		}
	}
}
int main(){
	scanf("%d", &N);
	M = N*N;
	for(int i=0;i<N; i++)
		for(int j=0;j<N;j++)
			scanf("%d", &chess[i][j]);

	f(0, 0);
	f(1, 0);

	printf("%d", w_max+b_max);
	return 0;
}