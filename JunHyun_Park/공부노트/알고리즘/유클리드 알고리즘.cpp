#include <cstdio>
// 유클리드 호제법
int gcd(int m, int n){
    while(n!=0){
        int r = m%n;
        m = n; n = r;
    }
    return m;
}
int lcm(int m, int n){
    return m*n / gcd(m,n);
}

int main(){
    int m, n;

    scanf("%d %d", &m, &n);

    for(int )
    printf("%d %d", gcd(m,n), lcm(m,n));
}