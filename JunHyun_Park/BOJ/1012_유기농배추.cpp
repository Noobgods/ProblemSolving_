#include<cstdio>	// 
int N,M,K, T, d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool A[51][51];
void f(int x, int y){
	A[x][y] = false;
	for(int i=0; i<4; i++){
		int dx = x+d[i][0];
		int dy = y+d[i][1];
		if(A[dx][dy] && (dx>=0 && dx<N && dy>=0 && dy<M)){
			f(dx, dy);
		}
	}
}
int main(){
	scanf("%d", &T);
	while(T--){
		
	int RN=0;
	scanf("%d %d %d", &N, &M, &K);

	for(int i=0; i<K; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		A[x][y] = true;
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(A[i][j]){
				f(i, j);
				RN++;
			}
		}
	}
	printf("%d\n",RN);
	}
	return 0;
}