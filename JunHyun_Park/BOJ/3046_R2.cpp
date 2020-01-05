#include<cstdio>    // 3046_R2 [¼öÇĞ]
int A,B,V;
int main(){
    scanf("%d %d %d",&A, &B, &V);
    int x = A-B;
    printf("%d", (V-B +x-1)/x);
    return 0;
}