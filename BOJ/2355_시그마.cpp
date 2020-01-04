#include<cstdio>    // 2355_시그마 [수학]
long long int A,B, x,y, s;
int main(){
    scanf("%lld %lld",&A, &B);
    if (B>=A)
        printf("%lld",(A+B)*(B-A+1)/2);
    else
        printf("%lld",(B+A)*(A-B+1)/2);
    return 0;
}