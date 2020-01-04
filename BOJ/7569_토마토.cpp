#include<cstdio>	// 7569_≈‰∏∂≈‰ [BFS]
#include<queue>
#include<tuple>
using namespace std;
int M,N,H,T[101][101][101],
d[6][3] = {{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}}, 
R[101][101][101], nr;
queue<tuple<int,int,int>> q;
void f(){
	while(!q.empty()){
		int x = get<0>(q.front()); 
		int y = get<1>(q.front()); 
		int z = get<2>(q.front()); 
		q.pop();
		for(int i=0; i<6; i++){
			int dx = x + d[i][0];
			int dy = y + d[i][1];
			int dz = z + d[i][2];
			if(T[dx][dy][dz] == 0 && (dx>=0 && dx<N && dy>=0 && dy<M && dz>=0 && dz<H)){
				T[dx][dy][dz] = 1;
				R[dx][dy][dz] = R[x][y][z]+1;
				q.push({dx,dy,dz});
			}
		}
	}
}
int main(){
	scanf("%d %d %d", &M, &N, &H);

	for(int k=0; k<H; k++){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &T[i][j][k]);
			if(T[i][j][k] == 1){
				R[i][j][k] = 0;
				q.push({i, j, k});
			}
			else 
				R[i][j][k] = -1;
		}
	}
	}
	f();
	
	for(int k=0; k<H; k++){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			nr = max(nr, R[i][j][k]);
			if(T[i][j][k] == 0) {
				nr = -1;
				i=N; j=M; k=H;
			}
		}
	}
	}
			
	printf("%d",nr);
	return 0;
}