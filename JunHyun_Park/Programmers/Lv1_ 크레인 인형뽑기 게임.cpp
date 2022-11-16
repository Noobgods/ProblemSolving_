#include <string>   // Level1_ 크레인 인형뽑기 게임 [스택]
#include <vector>
#include <stack>

#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> doll[board.size()]; 
    stack<int> basket;
    for(int i = board.size()-1; i>=0; i--){
        for(int j =0; j<board[i].size(); j++){
            if(board[i][j] != 0){
                doll[j].push(board[i][j]);
            }
        }
    }
    for(auto m : moves){
        if(!basket.empty() && !doll[m-1].empty() && basket.top() == doll[m-1].top()){
            basket.pop();
            doll[m-1].pop();
            answer+=2;
        }
        else{
            if(!doll[m-1].empty()){
                basket.push(doll[m-1].top());
                doll[m-1].pop();
            }
        }
    }

    return answer;
}

int main(){
    vector<vector<int>> board;
    vector<int> moves;
    int n, m; 
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        vector<int> vec;
        for(int j =0; j<n; j++){
            int k;
            cin >> k;
            vec.push_back(k);
        }
        board.push_back(vec);
    }

    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        moves.push_back(k);
    }

    cout << solution(board, moves);
    return 0;
}