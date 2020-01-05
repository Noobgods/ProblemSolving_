#include<cstdio>    // 12865_평범한배낭 [DP]
#include<algorithm>
using namespace std;
#define max(x,y) x>y?x:y
struct pack{
    int w, v;
};
int N,W, M, DP[2][100001]; 
pack A[101];

int main(){
    scanf("%d %d",&N, &W);
    for(int i=0; i<N; i++){
        scanf("%d %d", &A[i].w, &A[i].v);
    }

    for(int i=0; i<=N; i++){
        for(int j=0; j<=W; j++){
            if(i == 0 || j == 0)
                DP[i%2][j] = 0;
            else if(A[i-1].w <= j)
                DP[i%2][j] = max(A[i-1].v + DP[(i-1)%2][j - A[i-1].w], DP[(i-1)%2][j] );
            else
                DP[i%2][j] = DP[(i-1)%2][j];
        }
    }

    for(int i=0; i<=W; i++)
        M = max(DP[N%2][i], M);

    printf("%d", M);

    return 0;
}