#include<cstdio>    // 2568_전깃줄2 [DP], [LIS]
#include<algorithm>
#include<vector>
using namespace std;
#define max(x,y) x>y?x:y

vector<int> v1,v2;
struct R{
    int v1, v2, d1, d2;
};
int N;

R A[100001];

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


    vector<int> s1, s2;

    sort(&A[0], &A[N], compare_2);

    int M_2 = 0;
    v2.push_back(0);
    for(int i=0; i<N; i++){
        if(v2.back() < A[i].v1) {
            v2.push_back(A[i].v1);
            M_2++;
            A[i].d2 = M_2;
        }
        else {
            auto k = lower_bound(v2.begin(), v2.end(), A[i].v1);
            A[i].d2 = k - v2.begin();
            *k = A[i].v1;
        }
    }
    for(int i=N-1; i>=0; i--){
        if (A[i].d2 == M_2)
            M_2--;
        else 
            s2.push_back(A[i].v1);
    }
    
    sort(&A[0], &A[N], compare_1);
    
    int M_1 = 0;
    v1.push_back(0);
    for(int i=0; i<N; i++){
        if(v1.back() < A[i].v2) {
            v1.push_back(A[i].v2);
            M_1++;
            A[i].d1 = M_1;
        }
        else {
            auto k = lower_bound(v1.begin(), v1.end(), A[i].v2);
            A[i].d1 = k - v1.begin();
            *k = A[i].v2;
        }
    }

    for(int i=N-1; i>=0; i--){
        if (A[i].d1 == M_1) {
            M_1--;
        }
        else 
            s1.push_back(A[i].v1);
    }

    if(s1.size() > s2.size()){
        printf("%d\n", s2.size());
        sort(s2.begin(), s2.end());
        for(auto s : s2){
            printf("%d\n", s);
        }
    }
    else{
        printf("%d\n", s1.size());
        sort(s1.begin(), s1.end());
        for(auto s : s1){
            printf("%d\n", s);
        }
    }
    

    return 0;
}