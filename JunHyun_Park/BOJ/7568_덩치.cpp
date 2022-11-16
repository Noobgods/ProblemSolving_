#include<cstdio>	// 7568_덩치 [브루트포스]
int N, n[51][3];
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		scanf("%d %d", &n[i][0], &n[i][1]);
		n[i][2] = 1;
	}
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(n[i][0] < n[j][0] && n[i][1] < n[j][1])
				n[i][2]++;
	
	for(int i=0; i<N; i++)
		printf("%d ", n[i][2]);
	return 0;
}