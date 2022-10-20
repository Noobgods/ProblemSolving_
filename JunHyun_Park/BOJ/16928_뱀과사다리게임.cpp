#include <cstdio>   // 16928_뱀과사다리게임 [BFS]
#include <queue>
using namespace std;

int board[100][2], N, M, depth[101];
queue<int> q;

int main(){
    int now, l, s, next;

    scanf("%d %d", &N, &M);

    for(int i=2; i<101; i++) depth[i] = 17;

    while(N--){
        int l, s;
        scanf("%d %d", &l, &s);
        
        board[l][0] = s;
    }

    while(M--){
        int l, s;
        scanf("%d %d", &l, &s);
        
        board[l][1] = s;
    }

    depth[1] = 0;
    q.push(1);

    while (!q.empty()){
        now = q.front();
        q.pop();

        for(int i=now+1; i<=now+6; i++){
            next = depth[now]+1;
            if(i<100){
                l = board[i][0];
                s = board[i][1];
                
                if(l==0 && s==0){
                    if(depth[i] > next){
                        depth[i] = next;
                        q.push(i);
                    }
                }
                else{
                    if(depth[l] > next){
                        depth[l] = next;
                        q.push(l);
                    }
                    else if(depth[s] > next){
                        depth[s] = next;
                        q.push(s);
                    }
                }
            }
            else{
                if(depth[100] > next) depth[100] = next;
                break;
            }
        }
    }

    printf("%d\n", depth[100]);
}