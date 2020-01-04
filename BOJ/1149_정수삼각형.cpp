#include<cstdio>	// 1149_Á¤¼ö»ï°¢Çü [DP]
int min(int x, int y){ return x<y?x:y;}
int H[1000][3];
int main(){
    int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d %d", &H[i][0],&H[i][1],&H[i][2]);
	}
	for(int i=1; i<n; i++){
		H[i][0] += min(H[i-1][1], H[i-1][2]);
		H[i][1] += min(H[i-1][0], H[i-1][2]);
		H[i][2] += min(H[i-1][0], H[i-1][1]);
	}
		
	printf("%d", min(H[n-1][0], min(H[n-1][1], H[n-1][2])));
	return 0;
}