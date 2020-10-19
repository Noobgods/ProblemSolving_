#include <string>   // Level2_ 기능개발 [큐]
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for(auto p : progresses){
        q.push(p);
    }
    int idx=0, k;
    for (int i=0; idx < progresses.size(); i++){
        k = 0;
        while(q.front() + (speeds[idx] * i) >= 100 && !q.empty()){
            q.pop();
            k++;
            idx++;
        }
        if( k > 0) {
            answer.push_back(k);
        }
    }
    return answer;
}
int main(){
    int n;
    cin >> n;

    vector<int> progresses, speeds;

    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        progresses.push_back(k);
    }
    
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        speeds.push_back(k);
    }

    for(auto k : solution(progresses, speeds))
        cout << k << " ";
}