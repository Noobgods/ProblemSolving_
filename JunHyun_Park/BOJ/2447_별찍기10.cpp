#include<cstdio>    // 2447_별찍기10 [분할정복]
#include<cmath>
int N;
bool board[6562][6562];
void recu(int k){
    if(k==1) return;
    
    for(int r=0; r<N/k; r++)
        for(int z=0; z<N/k; z++)
    for(int i=k/3, x=0; x<k/3; x++){
        for(int j=k/3, y=0; y<k/3; y++){
            board[i+x+(k*r)][j+y+(k*z)] = true;
        }
    }

    recu(k/3);
}
int main(){
    scanf("%d", &N);
    
    recu(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}