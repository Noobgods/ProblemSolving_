#include<cstdio>	// 12100_2048(Easy) [브루트포스],[구현]
int N, S;
int A[21][21],T[21][21];

void mergeRight(){
    printf("Right ");
	for(int i=0; i<N; i++){
		for(int j=0; j<N-1; j++){
			if(A[i][j] == A[i][j+1]){
				A[i][j+1]*=2;
				A[i][j]=0;
			}
			if(A[i][j] && A[i][j+1] == 0){
				A[i][j+1] = A[i][j];
			}
		}
	}
}
void mergeLeft(){
    printf("Left ");
	for(int i=0; i<N; i++){
		for(int j=N-1; j>0; j--){
			if(A[i][j] == A[i][j-1]){
				A[i][j-1]*=2;
				A[i][j]=0;
			}
			if(A[i][j] && A[i][j-1] == 0){
				A[i][j-1] = A[i][j];
			}
		}
	}
}
void mergeDown(){
    printf("Down ");
	for(int i=0; i<N; i++){
		for(int j=0; j<N-1; j++){
			if(A[j][i] == A[j+1][i]){
				A[j+1][i]*=2;
				A[j][i]=0;
			}
			if(A[j][i] && A[j+1][i] == 0){
				A[j+1][i] = A[j][i];
			}
		}
	}
}
void mergeUp(){
    printf("Up ");
	for(int i=0; i<N; i++){
		for(int j=N-1; j>0; j++){
			if(A[j][i] == A[j-1][i]){
				A[j-1][i]*=2;
				A[j][i]=0;
			}
			if(A[j][i] && A[j-1][i] == 0){
				A[j-1][i] = A[j][i];
			}
		}
	}
}
void f(int x, int* max){
    printf("\n%d ", x);
	if(x<=0) {
        int m =0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(m < A[i][j]) m = A[i][j];
            }
        }
        if(*max < m) *max = m;
        printf("%d ", m);
        return;
    }
    mergeDown();
    f(x-1, max);
    mergeLeft();
    f(x-1, max);
    mergeRight();
    f(x-1, max);
    mergeUp();
    f(x-1, max);

}
int main(){
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&T[i][j]);
		}
	}
	int max = 0;
    f(1, &max);

    printf("%d", max);
	return 0;
}