#include<cstdio>    // 2217_로프 [그리디]
#include<algorithm>
using namespace std;

int A[100000];
bool compare(int x, int y){
    return x < y? 1:0;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &A[i]);
    }

    sort(&A[0], &A[N], compare);

    int max=0;
    for(int i=0;i<N; i++){
        if(max < A[i]*(N-i)){
            max = A[i]*(N-i);
        }
    }

    printf("%d", max);
    return 0;
}