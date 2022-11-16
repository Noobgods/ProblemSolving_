#include<cstdio>    // 11399 ATM [그리디]
#include<algorithm>
using namespace std;

int A[1001];
bool compare(int A, int B){
    return A < B ? 1:0;
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0; i<N;i++)
        scanf("%d", &A[i]);
    sort(&A[0], &A[N], compare);

    int k=0, R=0;
    for(int i=0;i<N; i++){ 
        k = k+A[i];
        R += k;
    }
    printf("%d", R);
    return 0;
}