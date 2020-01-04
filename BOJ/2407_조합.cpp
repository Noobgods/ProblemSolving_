#include<cstdio>	// 2407_조합 [수학][구현]
char f[2][101][160];
int N, K;
int main(){
    scanf("%d %d", &N, &K);
    for(int _n = 1; _n <= N; _n++){
        for(int _k = 0; _k <=K; _k++){
            if(_k ==  0 || _n == _k)
				f[_n%2][_k][0] = '1';
            else {
				for(int i=0; f[_n%2][_k][i] > 0; i++)
			    	f[_n%2][_k][i] = 0;
				for(int i= 0; f[(_n-1)%2][_k-1][i] > 0 || f[(_n-1)%2][_k][i] > 0; i++){
					int x=0, y=0, z=0;

					if( f[(_n-1)%2] [_k-1] [i] > 0)
						x = f[(_n-1)%2] [_k-1] [i] - '0';
					if( f[(_n-1)%2] [_k] [i] > 0)
						y = f[(_n-1)%2] [_k] [i] - '0';
					z = x + y;
					
					if(f[_n%2][_k][i] > 0) z+= f[_n%2][_k][i] - '0';
					
					f[_n%2][_k][i] = (char)('0'+z%10);
					if(z>9)
						f[_n%2][_k][i+1] = (char)(z/10 + '0');
				}
			}
		}
    }
	for(int i=159; i>= 0; i--){
		if(f[N%2][K][i] > 0)
	    	printf("%c", f[N%2][K][i]);
	}
	return 0;
}