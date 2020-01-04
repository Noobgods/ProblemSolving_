#include<cstdio>	// 13565 침투 [구현], [BFS]
int M, N, i, j;
bool map[1002][1002], s;
void go(int x, int y){
	if(y>=M) {s = true; return;}
	if(y<=0) return;
	if(x<=0) return;
	if(x>N) return;

	map[x][y] = true;
	if(!map[x][y+1] && !s) go(x, y+1);
	if(!map[x][y-1] && !s) go(x, y-1);
	if(!map[x+1][y] && !s) go(x+1, y);
	if(!map[x-1][y] && !s) go(x-1, y);
}
int main(){
	scanf("%d %d", &M, &N);
	for(i = 1; i<=M; i++){
		for(j = 1; j<=N; j++){
			scanf("%1d",&map[j][i]);
		}
	}
	for(i = 1; i<=M; i++){
		if(!map[i][1] && !s) go(i, 1);
	}
	if(s) printf("YES");
	else printf("NO");
	return 0;

}