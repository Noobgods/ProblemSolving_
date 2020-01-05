#include<cstdio>    // 11050_이항계수1 [수학]
int N, K;
int fact(int n){
    if(n<=1) return 1;
    return fact(n-1) * n;
}
int main(){
    scanf("%d %d", &N, &K);
    
    if (K==0) printf("1");
    else if (K<0 || K>N || N>10 || N<0) printf("0");
    else {
        fact(N);
        printf("%d", fact(N)/(fact(K)*fact(N-K)));
    }
    return 0;
}