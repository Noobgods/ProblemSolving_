#include<cstdio>    // 9251_LCS [DP]
#include<cstring>
#define max(x,y) x>y?x:y

char A[1001], B[1001];
int DP[2][1001], R, K;
int main(){
    scanf("%s\n%s",A,B);

    int lA = strlen(A), lB =strlen(B);
    for(int i=1; i <= lA; i++){
        for(int j=1; j <= lB; j++){
            if(A[i-1] == B[j-1]) 
                DP[i%2][j] = DP[(i-1)%2][j-1] +1;
            else 
                DP[i%2][j] = max(DP[i%2][j-1], DP[(i-1)%2][j]);
        }
    }

    printf("%d", DP[lA%2][lB]);
    return 0;
}