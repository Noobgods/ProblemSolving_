#include<cstdio>    // 2565_전깃줄 [DP]
#include<algorithm>
#include<vector>
using namespace std;
#define max(x,y) x>y?x:y

vector<int> v1,v2;
struct R{
    int v1, v2;
};
int N;
R A[501];
bool compare_1(R x, R y){
    return x.v1 < y.v1 ? 1: 0;
}
bool compare_2(R x, R y){
    return x.v2 < y.v2 ? 1: 0;
}

int main(){
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        scanf("%d %d", &A[i].v1, &A[i].v2);

    sort(&A[0], &A[N], compare_1);

    int M_1 = 0;
    v1.push_back(0);
    for(int i=0; i<N; i++){
        if(v1.back() < A[i].v2) {
            v1.push_back(A[i].v2);
            M_1++;
        }
        else {
            auto k = lower_bound(v1.begin(), v1.end(), A[i].v2);
            *k = A[i].v2;
        }
    }

    sort(&A[0], &A[N], compare_2);

    int M_2 = 0;
    v2.push_back(0);
    for(int i=0; i<N; i++){
        if(v2.back() < A[i].v1) {
            v2.push_back(A[i].v1);
            M_2++;
        }
        else {
            auto k = lower_bound(v2.begin(), v2.end(), A[i].v1);
            *k = A[i].v1;
        }
    }
    
    if(M_1 > M_2) printf("%d", N-M_1);
    else printf("%d", N-M_2);
    return 0;
}