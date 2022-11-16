#include <string>   // Level3_ 가장 먼 노드 [BFS]
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

#include<iostream>
using namespace std;

bool visit[20001];
int dst[20001];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    queue<int> q;
    for(int i=0; i<edge.size(); i++){
        graph[edge[i][0]-1][edge[i][1]-1] = true;
        graph[edge[i][1]-1][edge[i][0]-1] = true;
    }

    visit[0] = true;
    for(int i=1; i<n; i++){
        if(graph[0][i]){
            q.push(i);
            visit[i] = true;
            dst[i] = 1;
        }
    }
    
    int now;
    while(!q.empty()){
        now = q.front();
        q.pop();
        for(int i=0;i<n; i++){
            if(graph[now][i] && !visit[i]){
                visit[i] = true;
                dst[i] = dst[now]+1;
                q.push(i);
            }
        }
    }

    sort(dst, dst+n);

    int max = dst[n-1];
    answer = 1;
    for(int i = n-2; i>=0; i--){
        if(dst[i] < max) break;
        else answer++;
    }

    return answer;
}

// 입출력
int main(){
    int n, k;
    vector<vector<int>> edge;

    cin >> n >> k;

    for(int i=0; i<k; i++){
        vector<int> v;
        edge.push_back(v);
        for(int j =0; j<2; j++){
            int k;
            cin >> k;
            edge[i].push_back(k);
        }
    }

    cout << solution(n, edge);

}

