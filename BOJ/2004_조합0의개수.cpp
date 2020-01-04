#include<cstdio>    // 2004_조합0의개수 [수학], [조합]
#define min(x,y) x<y?x:y

long long int f(int n){
    long long int R=0;
    for(long long int i=5; i<=n; i*=5){
        R += n/i;
    }
    return R;
}

long long int t(int n){
    long long int R=0;
    for(long long int i=2; i<=n; i*=2){
        R += n/i;
    }
    return R;
}
int main(){
    long long int N,M,K;
    scanf("%lld %lld", &N,&M);

    long long int n = min(f(N)-(f(M)+f(N-M)),t(N) - (t(M) + t(N-M)));

    printf("%lld",n);
	return 0;
}