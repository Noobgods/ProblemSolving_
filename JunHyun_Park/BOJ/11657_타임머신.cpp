#include <cstdio>   //11657_타임머신 [벨만포드]
#define INF 10000000000
int N, M, node[6001][3];
long long city[501];
bool isInf;

int main(){
    scanf("%d %d", &N, &M);

    for(int i=0; i<M; i++)
        scanf("%d %d %d", &node[i][0], &node[i][1], &node[i][2]);

    city[1] = 0;
    for(int i=2; i<=N; i++)
        city[i] = INF;

    for(int i=2; i<=N; i++)
        for(int j=0; j<M; j++)
            if(city[node[j][0]] != INF && city[node[j][1]] > node[j][2] + city[node[j][0]])
                city[node[j][1]] = node[j][2] + city[node[j][0]];
    
    for(int j=0; j<M; j++){
        if(city[node[j][0]] != INF && city[node[j][1]] > node[j][2] + city[node[j][0]]){
            isInf = true;
            break;
        }
    }

    if(isInf) printf("-1\n");
    else{
        for(int i=2; i<=N; i++){
            if(city[i] >= INF)
                printf("-1\n");
            else
                printf("%lld\n", city[i]);
        }
    }

    return 0;
}