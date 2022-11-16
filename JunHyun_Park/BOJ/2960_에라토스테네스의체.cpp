#include<cstdio>    // 2960_에라토스테네스의체 [구현]
#include<list>
#include<algorithm>
using namespace std;
int N, K;
bool R[1001];
int f(int x){
    for(int i=x; i<=N; i+=x){
        if(!R[i]){
            if(K==1)
                return i;
            R[i] = 1;
            K--;
        }
    }
    return 0;
}
int main(){
    scanf("%d %d", &N, &K);

    int r;
    for(int i=2;i<=N;i++){
        r = f(i);
        if(f(i)) break;
    }
    printf("%d", r);

	return 0;
}