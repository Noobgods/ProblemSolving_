#include<cstdio>    // 2609_최대공약수와최소공배수 [수학]
int N,K;
int main(){
    scanf("%d %d",&N, &K);
    int i, j;
    if(N<K){
        int t = N;
        N = K;
        K = t;
    }

    for(i=1; N%(K/i)!=0;){
        i+=1;
        while(K%i != 0) i++;
    }
    
    for(j=1; (N*j)%K !=0;j++);
    printf("%d\n%d", K/i, N*j);
    return 0;
}