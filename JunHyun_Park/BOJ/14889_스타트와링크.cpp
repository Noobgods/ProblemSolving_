#include<cstdio>	// 14889_스타트와링크 [백트래킹], [브루트포스]
int A[21][21],t[2][10], N,gap = 1000000;
bool visited[20];
void f(int x, int y){
	if(x==N/2){
		int t1=0, t2=0, tgap=0, at=0, bt=0;
		for(int i=0; i<N; i++){
			if(visited[i]) t[0][at++] = i;
			else t[1][bt++] = i;
		}
		for(int i=0; i<N/2-1; i++){
			for(int j=i+1; j<N/2; j++){
				tgap += (A[t[0][i]][t[0][j]] + A[t[0][j]][t[0][i]]) - (A[t[1][i]][t[1][j]] + A[t[1][j]][t[1][i]]);
			}
		}
		if(tgap < 0) tgap = -tgap;
		if(tgap < gap) gap = tgap;

		return;
	}
	else for(int i=y; i<N; i++){
		if(!visited[i]){
			visited[i] = true;
			f(x+1, i+1);
			visited[i] = false;
		}
	}
}
int main(){
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &A[i][j]);

	f(0, 0);

	printf("%d", gap);
	return 0;
}