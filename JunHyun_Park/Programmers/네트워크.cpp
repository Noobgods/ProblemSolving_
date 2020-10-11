#include <string>   // Level3_ 네트워크 [BFS]
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

bool visit[200];

void bfs(int v, int n, vector<vector<int>> computers){
    queue<int> q;
    visit[v] = true;
    q.push(v);
    int now;
    while(!q.empty()){
        now = q.front();
        q.pop();
        for(int i =0; i<n; i++){
            if(computers[now][i] == 1 && !visit[i]){
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0; i<n; i++){
        if(!visit[i]){
            bfs(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}

int main(){
    int n;
    vector<vector<int>> computers;

    cin >> n;

    for(int i=0; i<n; i++){
        vector<int> v;
        computers.push_back(v);
        for(int j =0; j<n; j++){
            int k;
            cin >> k;
            computers[i].push_back(k);
        }
    }

    cout << solution(n, computers);
}