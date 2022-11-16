#include<cstdio> // 1629_곱셈 [수학], [분할정복]
#include<cmath>
int A, B, C;

int power(int x,int y){
    if(y==0) return 1;
    int k = power(x, y/2);
    int r = (1LL * k * k)%C;
    if(y%2) r = (1LL * r * x)%C;
    return r;
}
int main(){
    scanf("%d %d %d", &A, &B, &C);

    printf("%d", power(A,B));
    return 0;
}
