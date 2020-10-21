#include <string>   // Level1_ K번째수 [정렬]
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        vector<int>::iterator vi = array.begin();
        vector<int> v(vi + (commands[i][0]-1), vi + commands[i][1]);
        sort(v.begin(), v.end());
        

        answer.push_back(v[commands[i][2]-1]);
    }
    
    return answer;
}

int main(){
    int n, c_n;
    cin >> n >> c_n;
    vector<int> array;
    vector<vector<int>> commands;

    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        array.push_back(k);
    }
    for(int i=0; i<c_n; i++){
        vector<int> v;
        for(int j=0; j<3; j++){
            int k;
            cin >> k;
            v.push_back(k);
        }
        commands.push_back(v);
    }

    vector<int> answer = solution(array, commands);

    for(auto i:answer){
        cout << i << " ";
    }
    return 0;
}