#include<cstdio>	// 14500_테트로미노 [브루트포스]
#define max(x,y) x>y?x:y

bool omino[2][2] = {{1,1},{1,1}};
bool imino[1][4] = {1,1,1,1};
bool zmino[2][3] = {{1,1,0},{0,1,1}};
bool lmino[2][3] = {{1,1,1},{0,0,1}};
bool tmino[2][3] = {{1,1,1},{0,1,0}};
int N,M,A[505][505], R=0;

int o_mino(int x, int y){
	int sum=0;

	sum = A[x][y] + A[x+1][y] + A[x][y+1] + A[x+1][y+1];
	return sum;
}
int i_mino(int x, int y){
	int sum=0;

	if(y+3<=M) sum = A[x][y] + A[x][y+1] + A[x][y+2] + A[x][y+3];
	if(x+3<=N) sum = max(sum, A[x][y] + A[x+1][y] + A[x+2][y] + A[x+3][y]);
	return sum;
}
int z_mino(int x, int y){
	int sum[4]={0},r;
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			sum[0] += A[x+i][y+j] * zmino[i][j];
			sum[1] += A[x+i][y+j] * zmino[i][2-j];
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			sum[2] += A[x+i][y+j] * zmino[j][i];
			sum[3] += A[x+i][y+j] * zmino[j][2-i];
		}
	}
	r = max(sum[1], sum[0]);
	r = max(r, sum[2]);
	return max(r, sum[3]);
}
int l_mino1(int x, int y){
	int sum[4]={0},r=0;
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			sum[0] += A[x+i][y+j] * lmino[i][j];
			sum[1] += A[x+i][y+j] * lmino[i][2-j];
			sum[2] += A[x+i][y+j] * lmino[1-i][j];
			sum[3] += A[x+i][y+j] * lmino[1-i][2-j];
		}
	}
	r = max(sum[1], sum[0]);
	r = max(r, sum[2]);
	return max(r, sum[3]);
}
int l_mino2(int x, int y){
	int sum[4]={0},r;
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			sum[0] += A[x+i][y+j] * lmino[j][i];
			sum[1] += A[x+i][y+j] * lmino[j][2-i];
			sum[2] += A[x+i][y+j] * lmino[1-j][i];
			sum[3] += A[x+i][y+j] * lmino[1-j][2-i];
		}
	}
	r = max(sum[1], sum[0]);
	r = max(r, sum[2]);
	return max(r, sum[3]);
}
int t_mino(int x, int y){
	int sum[4]={0},r;
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			sum[0] += A[x+i][y+j] * tmino[i][j];
			sum[1] += A[x+i][y+j] * tmino[1-i][2-j];
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			sum[2] += A[x+i][y+j] * tmino[j][i];
			sum[3] += A[x+i][y+j] * tmino[1-j][2-i];
		}
	}
	r = max(sum[1], sum[0]);
	r = max(r, sum[2]);
	return max(r, sum[3]);
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			R = max(R, o_mino(i,j));
			R = max(R, t_mino(i,j));
			R = max(R, z_mino(i,j));
			R = max(R, i_mino(i,j));
			R = max(R, l_mino1(i,j));
			R = max(R, l_mino2(i,j));
		}
	}
	
	printf("%d", R);
	return 0;
}