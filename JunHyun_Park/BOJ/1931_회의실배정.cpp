#include<cstdio>    // 1931_회의실배정 [그리디]
#include<algorithm>
using namespace std;

struct lec{
    unsigned int x, y;
};
lec A[100001];
bool compare(lec A, lec B){
    if(A.y == B.y)
        return A.x < B.x ? 1:0;
    else
        return A.y < B.y ? 1:0;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%u %u",&A[i].x, &A[i].y);
    }
    sort(&A[0], &A[N], compare);
    int k =0, R= 0;
    for(int i=0;i<N;i++){
        if(R <= A[i].x) {
            R = A[i].y;
            k++;
        }
    }
    printf("%d", k);
    return 0;
}