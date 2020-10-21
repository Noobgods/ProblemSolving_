#include<cstdio>    // 2610_ 회의준비 [Union-Find] [플로이드 워셜]
#include<algorithm>
#include<vector>
using namespace std;

#define INF 100000
int N,M, Table[102][102], root[102], minVal[102], minIdx[102];

int find(int t){
   if(root[t] == t) return t; 
   else return root[t] = find(root[t]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;
    else{
        root[x] = y;
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) Table[i][j] = 100000;
        minVal[i] = INF;
        minIdx[i] = -1;
        root[i] = i;
        Table[i][i] = 0;
    }

    for(int i=0; i<M; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        Table[x][y] = Table[y][x] = 1;
        merge(x,y);
    }
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(Table[i][k] + Table[k][j] < Table[i][j])
                    Table[i][j] = Table[i][k] + Table[k][j];
            }
        }
    }

   for(int i = 1; i <= N; i++){
        int p1 = find(i);
        int max = -1;
        for(int j = 1; j <= N; j++){
            if(Table[i][j] == INF)continue;
            if(max < Table[i][j]) max = Table[i][j];
        }
        if(minVal[p1] > max){
            minIdx[p1] = i;
            minVal[p1] = max;
        }
    }
    
    vector<int> rep;

    for(int i=1; i<=N; i++){
        if(minIdx[i] != -1) 
            rep.push_back(minIdx[i]);
    }

    sort(rep.begin(), rep.end());

    printf("%d\n", rep.size());
    for(int i=0; i<rep.size(); i++){
        printf("%d\n", rep[i]);
    }
	return 0;
}