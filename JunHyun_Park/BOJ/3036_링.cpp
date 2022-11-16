#include<cstdio>    // 3036 링 [수학]
using namespace std;
int N, R[101];
int gcd(int m, int n){
    while(n!=0){
        int r = m%n;
        m = n; n = r;
    }
    return m;
}
int main(){
    scanf("%d", &N);

    for(int i=0;i<N;i++){
        scanf("%d", &R[i]);
    }

    for(int i=1; i<N; i++){
        int k = gcd(R[0], R[i]);
        
        printf("%d/%d\n", R[0]/k, R[i]/k);
    }
	return 0;
}