#include <string>   // Level2_ 스킬트리 [큐]
#include <vector>
#include <string.h>
#include <queue>

#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    queue<char> oq;

    bool is_prior[26];
    memset(is_prior, false, sizeof(char)*26);
    for(auto ch : skill){
        oq.push(ch);
        is_prior[ch-'A'] = true;
    }
    for(int i= 0; i<skill_trees.size(); i++){
        queue<char> cq = oq;
        bool is_possible = true;
        for(auto ch : skill_trees[i]){
            if(is_prior[ch-'A']){
                if(cq.front() == ch){
                    cq.pop();
                }
                else{
                    is_possible = false;
                    break;
                }
            }
        }
        if(is_possible) answer++;
    }
    return answer;
}

int main(){
    string skill;
    vector<string> skill_trees;
    int n;
    cin >>n;

    cin >> skill;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        skill_trees.push_back(s);
    }

    cout << solution(skill, skill_trees);

}