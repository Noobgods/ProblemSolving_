#include <string>   // Level3_ Á¤¼ö»ï°¢Çü [DP]
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> dp;
    vector<int> first;
    first.push_back(triangle[0][0]);
    dp.push_back(first);
    for(int i=1; i<triangle.size(); i++){
        vector<int> v;
        for(int j=0; j<triangle[i].size();j++){
            if ( j == 0 )
                v.push_back(triangle[i][j] + dp[i-1][j]);
            else if ( j == triangle[i].size()-1 )
                v.push_back(triangle[i][j] + dp[i-1][j-1]);
            else 
                v.push_back(max(triangle[i][j] + dp[i-1][j-1], triangle[i][j] + dp[i-1][j]));
        }
        dp.push_back(v);
    }
    
    for(int i=0;i<dp[dp.size()-1].size(); i++){
        answer = max(answer, dp[dp.size()-1][i]);    
    }

    return answer;
}

// ???
int main(){
    int n;
    cin >> n;
    vector<vector<int>> triangle;

    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=0; j<=i; j++){
            int k;
            cin >> k;
            v.push_back(k);
        }
        triangle.push_back(v);
    }
    cout << solution(triangle);
}