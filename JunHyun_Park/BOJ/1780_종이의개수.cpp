#include<cstdio>    // 1780_종이의개수 [분할정복]
using namespace std;
int N, S[3];
int board[2188][2188];
int k;
bool checkQuad(int x, int y, int size){
    int set = board[x][y];
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(board[i][j] == set);
            else return false;
        }
    }
    if(set == -1) S[0]++;
    if(set == 0) S[1]++;
    if(set == 1) S[2]++;
    return true;
}
void splice(int x, int y, int size){
    if(size == 0) return;
    if(checkQuad(x, y, size));
    else{
        int size1 = size/3;
        int size2 = (size*2)/3;
        
        splice(x, y, size1);
        splice(x, y+size1, size1);
        splice(x, y+size2, size1);

        splice(x+size1, y, size1);
        splice(x+size1, y+size1, size1);
        splice(x+size1, y+size2, size1);
        
        splice(x+size2, y, size1);
        splice(x+size2, y+size1, size1);
        splice(x+size2, y+size2, size1);
    }
}
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &board[i][j]);
        }
    }
    splice(0,0,N);

    printf("%d\n%d\n%d",S[0],S[1],S[2]);
    return 0;
}