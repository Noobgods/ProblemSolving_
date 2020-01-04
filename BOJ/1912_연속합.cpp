#include<cstdio>    // 1912_¿¬¼ÓÇÕ [DP]
#define max(x,y) x>y?x:y

int N, A[100002],DP[100002], M=-100000000;
int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    DP[0] = A[0];
    for(int i=1; i<N; i++){
        DP[i]= max(A[i] + DP[i-1], A[i]);
    }
    for(int i=0;i<N; i++)
        M = max(DP[i], M);
    printf("%d", M);

    return 0;
}