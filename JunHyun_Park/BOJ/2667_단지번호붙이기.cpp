#include<cstdio>	// 2667_단지번호붙이기 [DFS]
#include<algorithm>
using namespace std;
int N, d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}},R[1000], RN=0;
char A[26][26];
void f(int x, int y){
	A[x][y] = '0';
	R[RN]++;
	for(int i=0; i<4; i++){
		int dx = x+d[i][0];
		int dy = y+d[i][1];
		if(A[dx][dy] == '1'){
			f(dx, dy);
		}
	}
}
int main(){
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		scanf("%s", A[i]);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(A[i][j] == '1'){
				f(i, j);
				RN++;
			}
		}
	}
	if(RN>0)sort(&R[0], &R[RN]);
	printf("%d\n",RN);
	for(int i=0;i<RN; i++){
		printf("%d\n",R[i]);
	}
	return 0;
}