#include <cstdio>   // 6588_골드바흐의추측 [소수], [에라토스테네스의체]
bool prime[1000001] ={true, true};
void eratos(int n){
    for(int i=2; i*i<=n; ++i)
        if(!prime[i])
            for(int j=i*i; j<=n; j+=i)
                prime[j] = true;
}
int main(){
    eratos(1000000);
    while(1){
        int a;
        scanf("%d", &a);
        if(a == 0) break;
        for(int i=2;; ++i){
            if(i > a/2) {
                printf("Goldbach's conjecture is wrong.\n");
                break;
            }
            if(!prime[i] && !prime[a-i]){
                printf("%d = %d + %d\n", a, i, a-i); 
                break;
            }
        }
    }
    return 0;    
}