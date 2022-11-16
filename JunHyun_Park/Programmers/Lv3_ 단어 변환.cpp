#include <string> // Level3_ 단어변환 [dfs]
#include <vector>

#include <iostream>

using namespace std;

bool visit[52];
bool node[52][52];
int answer = INT_MAX;

void dfs(int n, int begin, int target, vector<string>& words){
    if(words[begin] == words[target]) {
        if (answer > n) 
            answer = n;
        return;
    }
    else {
        for(int i=0; i<words.size(); i++){
            if(!visit[i] && node[i][begin]){
                visit[i]=true;
                dfs(n+1, i, target, words);
                visit[i]= false;
            }
        }
    }  
}

bool NodeCheck(string begin, string target){
    int n = 0;
    for(int i=0; i<begin.size(); i++){
        if(begin[i] != target[i]) {
            if(n == 0)
                n++;
            else if(n > 0)
                return false;
        }
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);

    for(int i=0; i<words.size()-1; i++){
        for(int j=i+1; j<words.size(); j++){
            if(NodeCheck(words[i], words[j])){
                node[i][j] = node[j][i] = true;
            }
        }
    }
    int n_b= -1, n_t= -1;
    for(int i=0; i<words.size(); i++){
        if(target == words[i]) 
            n_t = i;
    }
    if( n_t >= 0)
        dfs(0, words.size()-1, n_t, words);
    else return 0;
    return answer;
}