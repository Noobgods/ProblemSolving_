#include<cstdio>    // 2610_회의준비
#include<algorithm>
using namespace std;

int N,M, Table[102][102], check[101];

void swap(int **x, int **y){
    int **t = x;
    x = y;
    y = t;
}
void sort(){
    for(int i=1;i<=N-1;i++){
        for(int j=i+1; j<=N; j++){
            if(Table[i][0] > Table[j][0]) swap(Table[i], Table[j]);
        }
    }
}
int main(){
    scanf("%d %d", &N, &M);

    for(int i=0; i<M; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        Table[x][y] = 1;
        Table[y][x] = 1;
    }

    for(int i=1; i<=N; i++){
        Table[i][i] = 1;
        Table[i][N+1] = i;
        for(int j=1; j<=N; j++){
            if(Table[i][j]) Table[i][0]++;
        }
    }

    sort();
    for(int i=1; i<=N; i++){
        for(int j= i+1; j<=N; j++){
            for(int k=0; k<=N+1; k++){
                
            }
        }
        
        printf("\n");
    }
	return 0;
}