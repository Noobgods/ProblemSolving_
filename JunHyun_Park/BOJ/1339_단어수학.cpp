#include <cstdio>   // 1339_단어수학 [수학], [백트래킹]
#include <cstring>
// 그리디/수학으로도 풀 수 있음.

int N, alpha[26]={-1,}, idx;
long max;
char S[11][9], C[11];
bool number[10];

int add(){
    long R=0;
    for(int i=0; i<N; i++){
        int k= strlen(S[i]);
        for(int j=k-1, l=1; j>=0; j--){
            R += alpha[S[i][j] - 'A'] * l;
            l*=10;
        }
    }
    return R;
}
void dfs(int n, int k){
    if( k==idx){
        int sum = add();
        if(sum > max){
            max = sum;
        } 
        return;
    }
    for(int i=n; i>9-idx; i--){
        if(!number[i]){
            number[i] = true;
            alpha[C[k]-'A'] = i;
            dfs(n, k+1);
            number[i] = false;
        }
    }
}
int main() {
    scanf("%d", &N);

    for(int i=0; i<N; i++)
        scanf("%s", S[i]);
    
    for(int i=0;i<N;i++){
        for(int j=0; j<strlen(S[i]); j++){
            if(!strchr(C, S[i][j])){
                C[idx++] = S[i][j];
                alpha[S[i][j]-'A'] = 0;
            }
        }
    }
    dfs(9,0);
    printf("%ld", max);
    return 0;
}

