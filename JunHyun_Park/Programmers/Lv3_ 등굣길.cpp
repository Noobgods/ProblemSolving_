#include <string>   // Level3_ 등굣길 [DP]
#include <vector>
#include <iostream>

#define MOD 1000000007
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int path[n+1][m+1];    
    
    for(int i=1;i<=n; i++){
        for(int j=1;j<=m; j++){
            path[i][j] = -1;
        }
    }
    
    for(int i=0; i<=n; i++){
        path[i][0] = 0;
    }
    
    for(int i=0; i<=m; i++){
        path[0][i] = 0;
    }

    path[1][1] = 1;

    for(auto puddle : puddles){
        path[puddle[1]][puddle[0]] = 0;
    }
    
    for(int i=1;i<=n; i++){
        for(int j=1;j<=m; j++){
            if(path[i][j] == -1){
                path[i][j] = (path[i-1][j] + path[i][j-1])%MOD;
            }
        }
    }

    return path[n][m];
}

// 입출력
int main(){
    int m, n;

    cin >> m >> n;

    vector<vector<int>> puddles;
    int pn;
    cin >> pn;
    for(int i=0; i<pn; i++){
        vector<int> v;
        for(int j =0; j<2; j++){
            int k;
            cin >> k;
            v.push_back(k);
        }
        puddles.push_back(v);
    }

    cout << solution(m,n,puddles);
    return 0;
}