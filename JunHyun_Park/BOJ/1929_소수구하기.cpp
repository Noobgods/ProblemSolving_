#include <cstdio>   // 1929_소수구하기 [소수], [수학]
int N, M;
int main(){
    scanf("%d %d", &N, &M);
    bool *prime = new bool[M]();
    prime[0] = prime[1] = true;
    for(int i=2; i*i <=M; i++)
        if(!prime[i])
            for(int j=i*i; j<=M; j+=i)
                prime[j]= true;

    for(int i=N; i<=M; i++)
        if(!prime[i])
            printf("%d\n", i);
        
    return 0;    
}