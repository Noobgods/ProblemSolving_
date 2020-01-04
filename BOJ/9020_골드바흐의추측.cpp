#include <cstdio>   // 9020_골드바흐의추측 [소수], [에라토스테네스의체]
int N;
bool prime[7500] ={true, true};
void eratos(int n){
    for(int i=2; i*i<=n; ++i)
        if(!prime[i])
            for(int j=i*i; j<=n; j+=i)
                prime[j] = true;
}
int main(){
    eratos(7500);
    scanf("%d", &N);
    while(N--){
        int a;
        scanf("%d", &a);
        for(int i=a/2; i>1; i--)
            if(!prime[i] && !prime[a-i]){
                printf("%d %d\n", i, a-i); break;
            }
    }
    return 0;    
}