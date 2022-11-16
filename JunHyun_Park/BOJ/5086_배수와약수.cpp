#include<cstdio>    // 5086_배수와약수 [수학]
using namespace std;
int main(){
    int n, k;
    for(;scanf("%d %d", &n, &k), n!=0 && k!=0; ){
        if(n < k && k%n == 0) printf("factor\n");
        else if(n > k && n%k == 0) printf("multiple\n");
        else printf("neither\n");
    }
    return 0;
}