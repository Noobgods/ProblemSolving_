#include<cstdio>	// 7576_토마토 [BFS]
#include<queue>
using namespace std;
int M,N,T[1001][1001], d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}, R[1001][1001], nr;
queue<pair<int, int>> q;
void f(){
	while(!q.empty()){
		int x = q.front().first; 
		int y = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int dx = x + d[i][0];
			int dy = y + d[i][1];
			if(T[dx][dy] == 0 && (dx>=0 && dx<N && dy>=0 && dy<M)){
				T[dx][dy] = 1;
				R[dx][dy] = R[x][y]+1;
				q.push({dx,dy});
			}
		}
	}
}
int main(){
	scanf("%d %d", &M, &N);

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &T[i][j]);
			if(T[i][j] == 1){
				R[i][j] = 0;
				q.push({i, j});
			}
			else 
				R[i][j] = -1;
		}
	}
	f();
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			nr = max(nr, R[i][j]);
			if(T[i][j] == 0) {
				nr = -1;
				i=N; j=M;
			}
		}
	}
			
	printf("%d",nr);
	return 0;
}