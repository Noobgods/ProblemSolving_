#include<cstdio>	// 12100_2048(Easy) [브루트포스],[구현]
int N, S;
int A[21][21],T[21][21];

int main(){
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&T[i][j]);
		}
	}
	
	return 0;
}