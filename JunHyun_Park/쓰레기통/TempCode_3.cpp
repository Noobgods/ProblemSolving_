#include<cstdio>    // 2610_회의준비
#include<algorithm>
#include<cstring>
using namespace std;

int N,M, Table[102][102], check[101];

int main(){
    scanf("%d %d", &N, &M);

    memset(Table, 1, sizeof(Table));
    for(int i=0; i<M; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        Table[x][y] = 1;
        Table[y][x] = 1;
    }

    for(int i=1; i<=N; i++){
        Table[i][i] = 1;
        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                if(Table[i][k] + Table[k][j] < Table[i][j])
                   Table[i][j] = Table[i][k] + Table[k][j];
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j= 1; j<=N; j++){
            printf("%d ", Table[i][j]);
        }
        printf("\n");
    }
	return 0;
}