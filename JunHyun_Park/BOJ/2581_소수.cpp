#include<cstdio>    // 2581_소수 [소수], [수학]
int N, M, s, r = -1;
bool prime[10001] ={true, true};
void eratos(int n){
    if(n <= 1) return;
    for(int i=2; i*i <=n; i++)
        if(!prime[i])
            for(int j=i*i; j<=n; j+=i)
                prime[j]= true;
}
int main(){
    scanf("%d %d", &N, &M);
    
    eratos(M);

    for(int i=N; i<=M; i++)
        if(!prime[i]){
            if(r == -1)
                r = i;
            s += i;
        }
    if(r == -1) printf("-1");
    else printf("%d\n%d", s, r);
    return 0;    
}