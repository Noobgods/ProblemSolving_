#include<cstdio>    // 10989_수정렬하기 [정렬]
#include<vector>
using namespace std;

int c[10001];
int main(){
    int n;
    scanf("%d", &n);
        
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        
        c[a]++;
    }

    int ep = 0;
    for(int i=1; i<10001; i++){
        if(c[i] > 0){
            for(int j=0; j<c[i]; j++){
                printf("%d\n", i);
                ep++;
            }
        }
        if(ep == n) break;
    }
    return 0;
}