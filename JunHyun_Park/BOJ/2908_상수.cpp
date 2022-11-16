#include<cstdio>    // 2908_상수 [문자열처리]
#include<cstdlib>
#define max(x,y) x>y?x:y
char A[4], B[4];
int main(){
    scanf("%s %s", A, B);

    char t = A[2];
    A[2] = A[0];
    A[0] = t;

    t =  B[2];
    B[2] = B[0];
    B[0] = t;

    int M = max(atoi(A),atoi(B));
    printf("%d", M);
    return 0;
}