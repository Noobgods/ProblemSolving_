#include<cstdio>    // 1978_소수찾기 [소수], [수학]
bool prime[1001] = {true, true};
int N, R;
void eratos(int n){
    if(n<=1) return;
    for(int i=2; i*i <= n; i++)
        if(!prime[i])
            for(int j= i*i; j<=n; j+=i)
                prime[j] = true;
}
int main(){
    scanf("%d", &N);
    eratos(1000);
    while(N--){
        int p;
        scanf("%d", &p);
        if(!prime[p]) R++;
    }
    printf("%d", R);
    return 0;
}