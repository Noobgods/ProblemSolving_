#include <cstdio>   // 4948_베르트랑공준 [소수], [에라토스테네스의체], [구현]
int N;
bool prime[246914] ={true, true};
void eratos(int n){
    for(int i=2; i*i<=n; ++i)
        if(!prime[i])
            for(int j=i*i; j<=n; j+=i)
                prime[j] = true;
}
int main(){
    int max = 2;

    while(1){
        int s = 0;
        scanf("%d", &N);
        if (N == 0) break;
        eratos(123456 *2);
        for(int i=N+1; i<=2*N; i++)
            if(!prime[i]) s++;
        printf("%d\n", s);
    }
    return 0;    
}