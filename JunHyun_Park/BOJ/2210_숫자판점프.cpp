#include<cstdio>    // 2210_숫자판점프 [백트래킹]
#define N 5
int A[5][5], R, P[6] = {1, 10, 100, 1000, 10000, 100000}; 
int d[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
bool C[1000000];
void f(int x,int y, int n, int K){
    if(n==6) {
        if(!C[K]){
            C[K] = true;
            R++;
        } 
        return;
    }
    K += A[x][y] * P[n];
    for(int i=0;i<4;i++){
        int dx = x+d[i][0];
        int dy = y+d[i][1];
        if(dx>=0 && dx<5 && dy>=0 && dy<5)
            f(dx,dy,n+1, K);
    }
}
int main(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &A[i][j]);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            f(i,j,0,0);
    
    printf("%d", R);
    return 0;
}