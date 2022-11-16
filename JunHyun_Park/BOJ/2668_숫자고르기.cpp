#include<cstdio>    // 2668_숫자고르기 [DFS]
using namespace std;

int N, A[102], S;
bool V[102];
bool f(int x, int s){
    bool r;
    if(s == x) {
        V[x] = true;
        r = false;
    }
    else if(!V[x]){
        V[x] = true;
        r = f(A[x], s);
        if(r) V[x] = false;
    }
    else r = true;
    return r;
} 
int main(){
    scanf("%d", &N);

    for(int i=1; i<=N; i++)
        scanf("%d",A+i);

    for(int i=1; i<=N; i++){
        if(A[i] == i) V[i] = true;
        else f(A[i], i);
    }

    for(int i=1; i<=N; i++)
        S += V[i];

    printf("%d\n", S);
    for(int i=1; i<=N; i++)
        if(V[i]) printf("%d\n",i);
    
	return 0;
}