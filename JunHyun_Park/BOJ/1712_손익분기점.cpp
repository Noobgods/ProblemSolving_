#include<cstdio>    // 1712_손익분기점 [수학]
int A,B,C;
int main(){
    scanf("%d %d %d",&A, &B, &C);
    int x= C-B;
    if(x<=0)
        printf("-1\n");
    else
       printf("%d",A/x+1);
    return 0;
}