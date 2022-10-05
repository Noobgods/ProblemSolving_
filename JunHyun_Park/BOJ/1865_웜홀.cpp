#include <cstdio>   //1865_¿úÈ¦ [º§¸¸Æ÷µå]
#include <vector>
#include <tuple>
using namespace std;
#define INF 1000000000
int TC, N, M, W;
vector<tuple<int,int,int>> road;

int main(){
    scanf("%d",&TC);
    while(TC--){
        vector<tuple<int,int,int>> road;
        int node[501], x, y, z;;
        bool isInf = false;

        scanf("%d %d %d", &N, &M, &W);
        for(int i=0; i<M; i++){
            scanf("%d %d %d", &x, &y, &z);
            road.push_back(make_tuple(x,y,z));
            road.push_back(make_tuple(y,x,z));
        }

        for(int i=0; i<W; i++){
            scanf("%d %d %d", &x, &y, &z);
            road.push_back(make_tuple(x,y,-z));
        }

        for(int j=1; j<=N; j++)
            node[j] = INF;
        node[y] = 0;

        for(int j=1; j<=N; j++){
            isInf = 0;
            for(int k=0; k<road.size(); k++){
                int x = get<0>(road[k]);
                int y = get<1>(road[k]);
                int w = get<2>(road[k]);
                if(node[x] != INF && node[y] > w + node[x]){
                    node[y] = w + node[x];
                    isInf = 1;
                }
            }
            if(!isInf) break; 
        }

        if(isInf) printf("YES\n");
        else    printf("NO\n");
    }

    return 0;
}