#include<cstdio>       // 11047_동전0 [그리디]
int N, K, A[10],R;
int main(){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d",&A[i]);

    for(int i=N-1; i>=0;){
        if(A[i] <= K){
            R++;
            K -= A[i];
        }
        else
            i--;
    }
    printf("%d", R);
    return 0;
}