#include<cstdio>    // 1914_하노이탑 [재귀], [구현]
#define upper(x) x>3?1:x
#define lower(x) x<1?3:x

int N, len=0;
void f(int n, int i, int j){
    if(n==N) return;

    if(n%2){
        f(n+1, lower(j-1), lower(i-1));
        printf("%d %d\n", i, j); 
        f(n+1, upper(j+1), upper(i+1));
    }
    else{
        f(n+1, upper(j+1), upper(i+1));
        printf("%d %d\n", i, j); 
        f(n+1, lower(j-1), lower(i-1));
    }
}

int main(){
    scanf("%d",&N);
    
    int S[10000] = {1,0,};

    for(int i=1;i<N;i++){
        int t = 0;
        S[0] = S[0]*2+1;    // 연산
        for(int j=0;j<=len; j++){   
            if(j>0) S[j] = S[j]*2;  // 자릿수 연산
            if(S[j] > 9){   // 올림일때
                if(t>0) S[j] += t;  // 올림 더하기
                t = S[j] /10;   // 다음 해 올림
                S[j] = S[j] % 10;   // 올리고 나머지
                if(j == len) {  // 길이
                    len++;
                }
            }
            else {
                S[j] +=t;
                t=0;
            }
        }
    }
    
    for(int j=len; j>=0; j--)
        printf("%d",S[j]);
    printf("\n");
    if(N<=20) f(0,1,3);
    return 0;
}