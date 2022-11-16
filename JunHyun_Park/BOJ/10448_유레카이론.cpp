#include<cstdio>	// 10448 유레카이론 [브루트포스]
int T, N, i, j, k, tree[45];
int main(){
	for(i = 1; i<=44; i++)
		tree[i] = (i * ( i + 1) )/2;
	for(scanf("%d", &T); T--;){
		scanf("%d", &N);
		bool c = true;
		for(i = 1 ; i <= 44 && c; i++){
			for(j = 1; j <= 44 && c; j++){
				for(k =1; k<= 44 && c; k++){
					if(N == tree[i] + tree[j] + tree[k]) {
						printf("1\n"); c = false;
					}
				}
			}
		}
		if(c) printf("0\n");
	}
	return 0;
}