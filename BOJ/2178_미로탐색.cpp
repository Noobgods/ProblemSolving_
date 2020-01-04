#include<cstdio>	// 2178_¹Ì·ÎÅ½»ö [BFS]
#include<queue>
using namespace std;
int N,M, d[4][2]= {{1,0}, {0,1},{-1,0},{0,-1}},R=0;
int C[101][101];
char A[101][101];
void f(int x, int y){
	queue<pair<int, int>> q;
	q.push(make_pair(x,y));
	A[x][y] = '0';
	
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
		int dx = x+d[i][0];
		int dy = y+d[i][1];
		if((dx>=0 && dx<N && dy>=0 && dy<M) && A[dx][dy] =='1') {
			A[dx][dy] = '0';
			C[dx][dy] = C[x][y] + 1;
			q.push(make_pair(dx,dy));
		}
	}
	}
}
int main(){
	scanf("%d %d\n", &N, &M);

	for(int i=0; i<N; i++)
		scanf("%s", A[i]);

	f(0,0);
	printf("%d",C[N-1][M-1]+1);
	return 0;
}