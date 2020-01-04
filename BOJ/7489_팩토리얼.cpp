#include<cstdio>    // 7489_팩토리얼 [수학]

int T;
long long int N;
long long int f(long long int n){
    long long int R=0;
    for(long long int i=5; i<=n; i*=5){
        R += n/i;
    }
    return R;
}
int main(){
    for(scanf("%d",&T); T;T--){
        long long int S = 1;
        int K = 0;
        scanf("%lld", &N);
        
        for(long long int i=2; i<=N; i++){
            S = (S*i) %10000000000;
            int r = f(i);
            while(K<r) {
                S/=10;
                K++;    
            }
        }

        printf("%d\n",S%10);
    }
	return 0;
}