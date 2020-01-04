#include<cstdio>    // 6064_카잉달력 [규칙], [수학]
int Z;
int gcd(int x, int y){
    if(y == 0)
        return x;
    else
    return gcd(y, x % y);
}
int main(){
    scanf("%d", &Z);

    while(Z--){
        int M, N, X, Y, s=1;
        scanf("%d %d %d %d", &M, &N, &X, &Y);
        int _x=X, _y=Y, max = M * N /gcd(M, N);
        
        while(1) {
            if(_x > max || _y > max) {s = -1; break;}
            else if(_x > _y)
                _y += N;
            else if (_x < _y)
                _x += M;
            else {s = _x; break;}
        }

        printf("%d\n", s);   
    }
    return 0;    
}