#include<cstdio>    // 2659_십자카드문제 [DFS]
#include<list>
#include<algorithm>
using namespace std;
int N[4], C, R=1;
bool S[10000];
int f(int x[4]){
    int clock=9999;
    for(int i=0; i<4; i++){
        int k=(x[i%4]*1000)+ (x[(i+1)%4]*100) +(x[(i+2)%4]*10)+ x[(i+3)%4];
        if(clock > k) clock = k;
    }
    return clock;
}
void dfs(int x[4], int y){
    if(y < 0) {
        int k = f(x);
        if(k<C && !S[k]){
            R++;
        }
        S[k]=1;
        return;
    }
    for(int i=1; i<=9; i++){
        x[y] = i;
        dfs(x, y-1);
    }
}
int main(){
    scanf("%d %d %d %d", N, N+1, N+2, N+3);

    int r;
    C= f(N);

    int K[4] = {1,1,1,1};
    dfs(K, 3);

    printf("%d", R);

	return 0;
}