#include <string>   // Level1_ 모의고사 [구현]
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one[5] = {1,2,3,4,5};
    int two[8] = {2,1,2,3,2,4,2,5};
    int three[10] = {3,3,1,1,2,2,4,4,5,5};
    int kingOfMath[3] = {0,0,0};
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == one[i%5])
            kingOfMath[0]++;
        if(answers[i] == two[i%8])
            kingOfMath[1]++;
        if(answers[i] == three[i%10])
            kingOfMath[2]++;
    }
    int m = max(kingOfMath[0], max(kingOfMath[1], kingOfMath[2]));
    if (m == kingOfMath[0]) answer.push_back(1);
    if (m == kingOfMath[1]) answer.push_back(2);
    if (m == kingOfMath[2]) answer.push_back(3);
    return answer;
}
int main(){
    vector<int> answers;
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int k;
        cin >>k;
        answers.push_back(k);
    }

    vector<int> answer = solution(answers);

    for(auto ans : answer){
        cout << ans << " ";
    }
}