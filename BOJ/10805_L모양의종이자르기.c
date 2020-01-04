#include <stdio.h>  // 10805_L모양의종이자르기 [구현]
#define min(a,b) ((a) < (b) ? (a) : (b))
 
int L[51][51][51][51];
int R[51][51];
int res;
 
int func_L(int h1, int w1, int h2, int w2){
    int w, h;
 
    if (L[h1][w1][h2][w2] != 0) return L[h1][w1][h2][w2];
 
    int ret = 0x7fffffff;
    int h3 = h1 - h2;
    int w3 = w1 - w2;
 
    // 세로 자르기
    for (w = 1; w < w1; w++){
        if (w < w3) ret = min(ret, func_R(h1, w) + func_L(h1, w1 - w, h2, w2));
        else if (w > w3) ret = min(ret, func_L(h1, w, h2, w - w3) + func_R(h3, w1 - w));
        else ret = min(ret, func_R(h1, w3) + func_R(h3, w2));
    }
 
    // 가로 자르기
    for (h = 1; h < h1; h++){
        if (h < h2) ret = min(ret, func_R(h, w3) + func_L(h1 - h, w1, h2 - h, w2));
        else if (h > h2) ret = min(ret, func_L(h, w1, h2, w2) + func_R(h1 - h, w1));
        else ret = min(ret, func_R(h2, w3) + func_R(h3, w1));
    }
 
    return L[h1][w1][h2][w2] = ret;
}
 
int func_R(int H, int W){
    int h, w, ret = 0x7fffffff;
 
    if (R[H][W] != 0) return R[H][W];
 
    // 세로 자르기
    for (w = 1; w < W; w++)
        ret = min(ret, func_R(H, w) + func_R(H, W - w));
 
    // 가로 자르기
    for (h = 1; h < H; h++)
        ret = min(ret, func_R(h, W) + func_R(H - h, W));
 
    return R[H][W] = R[W][H] = ret;
}
 
int main(){
    int h1, w1, h2, w2, i = 0;
    res = 0;
 
    // initialize
    for (i = 0; i <= 50; i++){
        R[i][i] = 1;
        R[i][1] = i;
        R[1][i] = i;
    }

    scanf("%d %d %d %d", &h1, &w1, &h2, &w2);
 
    res = func_L(h1, w1, h2, w2);
    
    printf("%d\n", res);
}