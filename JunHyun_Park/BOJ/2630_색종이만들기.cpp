#include<cstdio>    // 2630_색종이만들기 [분할정복]
using namespace std;
int white, black, N;
bool board[129][129];
bool checkQuad(int x1, int y1, int x2, int y2){
    bool set = board[x1][y1];
    for(int i=x1; i<x2; i++){
        for(int j=y1; j<y2; j++){
            if(board[i][j] == set);
            else return false;
        }
    }
    if(set) black++;
    else white++;
    return true;
}
void quad(int x1, int y1, int x2, int y2){
    if(x1 == x2 || y1 == y2) return;
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;

    if(checkQuad(x1, y1, xm, ym));
    else quad(x1, y1, xm, ym);
    
    if(checkQuad(x1, ym, xm, y2));
    else quad(x1, ym, xm, y2);

    if(checkQuad(xm, y1, x2, ym));
    else quad(xm, y1, x2, ym);

    if(checkQuad(xm, ym, x2, y2));
    else quad(xm, ym, x2, y2);
}
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &board[i][j]);
        }
    }
    quad(0,0,N,N);
    printf("%d\n%d",white, black);
    return 0;
}