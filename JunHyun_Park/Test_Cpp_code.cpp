#include <cstdio>
#include <algorithm>
using namespace std;

int N, C, x[200000];
int main(){
    scanf("%d %d", &N, &C);

    for(int i=0; i<N; i++){
        scanf("%d", &x[i]);
    }
    sort(x, x+N);

    
    return 0;
}