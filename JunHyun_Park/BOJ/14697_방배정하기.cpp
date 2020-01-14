#include<cstdio>    // 14697_방배정하기 [브루트포스]
int A[3],N, x, y, z;
int main(){
    scanf("%d %d %d %d", A, A+1, A+2 ,&N);

    for(int i=0; i<=200; i++){
        x = A[0]*i;
        for(int j=0; j<=200; j++){
            y = A[1]*j;
            for(int k=0;k<=200; k++){
                z = A[2]*k;
                if(x+y+z == N){
                    printf("1\n");
                    return 0;
                }
            }
        }
    }
    printf("0\n");
	return 0;
}