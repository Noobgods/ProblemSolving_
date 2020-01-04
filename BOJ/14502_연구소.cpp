#include<cstdio>    // 14502_연구소 [BFS], [DFS], [브루트포스]
#include<queue>
using namespace std;
int la[8][8], N, M, d[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}}, vr[8][8], R=64;

int virus(int _x,int _y){
    queue<pair<int,int>> q;
    q.push({_x,_y});
    int sp =0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for(int i=0; i<4; i++){
            int dx = x+d[i][0];
            int dy = y+d[i][1];
            if(la[dx][dy] == 0 && vr[dx][dy] == 0 && (dx >=0 && dx <N && dy >= 0 && dy <M)){
                vr[dx][dy] = 2;
                sp++;
                q.push({dx,dy});
            }
        }
    }
    return sp;
}
void wall(int k, int n){
    if (k==N*M) return;
    else if(n==3) {
        int sp = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(la[i][j]==2) sp += virus(i, j);
            }
        }
        if (R>sp) R = sp;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                vr[i][j] = 0;
    }
    else for(int i=k;i<N*M;i++){
        int x= i/M;
        int y= i%M;
        if(la[x][y] == 0){
            la[x][y] = 1;
            wall(k+1, n+1);
            la[x][y] = 0;
        }
    }
}
int main(){
    int d, k= 0;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N; i++){
        for(int j=0;j<M;j++){
            scanf("%d", &la[i][j]);
            if(la[i][j] != 0) k++;
        }
    }

    wall(0,0);
    printf("%d", N*M -R -k-3);

    return 0;
}