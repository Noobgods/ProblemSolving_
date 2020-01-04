#include<cstdio>    // 1085_직사각형에서탈출 [수학]
int C(int x,int y){
    return x<y?x:y;
}
int x,y,w,h;
int main(){
    scanf("%d%d%d%d",&x,&y,&w,&h);
    printf("%d",C(C(C(w-x,x),y),h-y));
    return 0;
}