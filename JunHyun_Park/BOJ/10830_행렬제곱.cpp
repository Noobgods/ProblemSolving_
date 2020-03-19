#include<cstdio> // 10830_???? [??]
#include<cmath>
#define REM 1000

int A[5][5], N;
long long int M;
int(*sub (int (*a)[5], int (*b)[5]))[5]{
    int (*s)[5] = new int[5][5];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            s[i][j] = 0;
            for(int k=0; k<N; k++){
                s[i][j] += (a[i][k] * b[k][j]);
            }
            s[i][j] %= REM;
        }
    }
    delete a;
    delete b;
    return s;
}
int(* power(int(* x)[5], long long int y))[5]{
    if(y==0){
        int (*s)[5] = new int[5][5]{{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
        return s;
    } 
    int(* k)[5] = power(x, y/2);
    int(* r)[5] = sub(k,k);
    if(y%2) r = sub(r,x);
    return r;
}
int main(){
    scanf("%d %lld", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &A[i][j]);
        }
    }
    int (*S)[5]= power(A, M);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }
    delete S;
    return 0;
}
