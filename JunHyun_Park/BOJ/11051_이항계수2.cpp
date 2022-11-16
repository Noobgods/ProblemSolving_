#include<cstdio>    // 11051_이항계수2 [수학], [DP]
unsigned long long int f[2][1001];
int N, K;
int main(){
    scanf("%d %d", &N, &K);
    for(int _n = 1; _n <= N; _n++){
        for(int _k = 0; _k <=K; _k++){
            if(_k ==  0 || _n == _k) f[_n%2][_k] = 1;
            else f[_n%2][_k] = (f[(_n-1)%2][_k-1] + f[(_n-1)%2][_k] )%10007;
        }
    }
    printf("%llu", f[N%2][K]);
    return 0;
}