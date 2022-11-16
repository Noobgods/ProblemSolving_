#include<cstdio> // 2740_행렬곱셈 [수학]
#include<cmath>

int A1[101][101], A2[101][101], S[101][101];
int N1, M1, N2, M2;
int main(){
    scanf("%d %d", &N1, &M1);
    for(int i=0; i<N1; i++){
        for(int j=0; j<M1; j++){
            scanf("%d", &A1[i][j]);
        }
    }
    scanf("%d %d", &N2, &M2);
    for(int i=0; i<N2; i++){
        for(int j=0; j<M2; j++){
            scanf("%d", &A2[i][j]);
        }
    }
    for(int i=0; i<N1; i++){
        for(int j=0; j<M2; j++){
            for(int k=0; k<M1; k++){
                S[i][j] += A1[i][k] * A2[k][j];
            }
        }
    }
    for(int i=0; i<N1; i++){
        for(int j=0; j<M2; j++){
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }
    return 0;
}
