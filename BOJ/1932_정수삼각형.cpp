#include<cstdio>    // 1932_Á¤¼ö»ï°¢Çü [DP]
int A[501][501];
int S[501][501];
int n;
int max(int x, int y){ return x>y?x:y;}
void sum(int i, int j) {
	if(i == n) return;
	if(i==0)
		S[i][j] = A[0][0];
	else if(j==i)
		S[i][j] = S[i-1][j-1] + A[i][j];
	else if(j==0)
		S[i][j] = S[i-1][j] + A[i][j];
	else if(0 < j && j < i)
		S[i][j] = A[i][j] + max(S[i-1][j], S[i-1][j-1]);

	sum(i+1, j);
	if(i==j)
		sum(i+1, j+1);
}

int main() {
	int result=0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i+1; j++)
			scanf("%d", &A[i][j]);

	sum(0,0);
	for(int i =0; i<n; i++)
		if(result < S[n-1][i]) result = S[n-1][i];
	
	printf("%d", result);
	return 0;
}