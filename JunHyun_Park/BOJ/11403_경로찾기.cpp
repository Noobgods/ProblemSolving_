#include<cstdio>    // 11403_경로찾기 [BFS], [DFS], [플로이드워셜알고리즘]
//플로이드 워셜 알고리즘을 사용하여 답을 구함

int main(){
    int N;
    bool A[101][101];
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &A[i][j]);

    for(int k=0; k<N; k++)
        for(int i=0; i<N; i++)
            for(int j=0;j<N; j++)
                if(A[i][k] && A[k][j])
                    A[i][j] = 1;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    return 0;
}