#include<cstdio>    // 1992_쿼드트리 [분할정복]
using namespace std;
int N;
bool board[65][65];
bool checkQuad(int x1, int y1, int x2, int y2){
    bool set = board[x1][y1];
    for(int i=x1; i<x2; i++){
        for(int j=y1; j<y2; j++){
            if(board[i][j] == set);
            else return false;
        }
    }
    if(set) printf("1");
    else printf("0");
    return true;
}
void quad(int x1, int y1, int x2, int y2){
    if(x1 == x2 || y1 == y2) return;

    if(checkQuad(x1, y1, x2, y2));
    else{
        int xm = (x1 + x2) / 2;
        int ym = (y1 + y2) / 2;

        printf("(");
        quad(x1, y1, xm, ym);
        quad(x1, ym, xm, y2);
        quad(xm, y1, x2, ym);
        quad(xm, ym, x2, y2);
        printf(")");
    }
}
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &board[i][j]);
        }
    }
    quad(0,0,N,N);
    return 0;
}