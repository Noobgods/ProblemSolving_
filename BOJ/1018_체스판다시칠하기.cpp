#include<cstdio>	//1018_체스판다시칠하기 [브루트포스], [시뮬레이션]
int N, M;
char c[51][51];
int main(){
	scanf("%d %d\n", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%s", c[i]);
	int b= 0, w= 0, BW = 0, min = 64;
	char bw[2] = {'B', 'W'};
	for(int x=0; x<N-7; x++){
		for(int y=0; y<M-7; y++){
			BW = b = w = 0;
			for(int i=x; i<(x+8); i++){
				for(int j=y; j<(y+8); j++){
					if(bw[BW%2] != c[i][j]) b++;
					if(bw[(BW+1)%2] != c[i][j])	w++;
					BW++;
				}
				BW++;
			}
			if(b < min) min = b;
			if(w < min) min = w;
		}
	}
	printf("%d\n", min);

	return 0;
}
