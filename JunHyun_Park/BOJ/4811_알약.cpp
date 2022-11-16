#include <cstdio>   // 4811_알약 [DP]

long long pill[32][31] = { {1,}, {1,1}};
int main(){
    for(int i=1; i<=30; i++){
        for(int j=1; j<i; j++){
            long long sum = 0;
            for (int k=j-1; k<i-1; k++){
                sum += pill[i-1][k];
            }
            pill[i][j] = sum;
        }
        for(int j=0; j<i; j++){
            pill[i+1][0] += pill[i][j];
        }
    }
    while(1){
        int n;
        scanf("%d", &n);

        if(n == 0) break;

        printf("%lld\n", pill[n+1][0]);
    }
    return 0;
}