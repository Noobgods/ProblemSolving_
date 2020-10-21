#include<cstdio>    // 2610_회의준비
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define INF 100000
int N,M, Table[102][102], check[102], maxTime[102], minVal[102], minIdx[102];
int k=1;

void dfs(int x){
    check[x] = k;
    for(int i=1; i<=N; i++){
        if(check[i] ==0 && Table[x][i] != INF){
            dfs(i);
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) Table[i][j] = 100000;
        minVal[i] = INF, minIdx[i] = -1, Table[i][i] = 0;
    }
    for(int i=0; i<M; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        Table[x][y] = 1;
        Table[y][x] = 1;
    }

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(Table[i][k] + Table[k][j] < Table[i][j])
                    Table[i][j] = Table[i][k] + Table[k][j];
            }
        }
    }
    
    vector<int> rep;

    for(int i=1; i<=N; i++){
        if(check[i] == 0){
            dfs(i);
            k++;
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(Table[i][j] != INF){
                if(maxTime[i] < Table[i][j]){
                    maxTime[i] = Table[i][j];
                }
            }               
        }
        if(maxTime[i] < minVal[check[i]]) {
            minIdx[check[i]] = i;
            minVal[check[i]] = maxTime[i];
        }
    }

    for(int i=1; i<k; i++){
        rep.push_back(minIdx[i]);
    }

    sort(rep.begin(), rep.end());
    printf("%lu\n", rep.size());

    for(int i=0; i<rep.size(); i++){
        printf("%d\n", rep[i]);
    }
	return 0;
}