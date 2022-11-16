#include<iostream>    // 15956_숏코딩 [문자열처리]
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;

/** 문자열 토큰 함수;
*   @brief  문자열을 문자열로 토큰을 나누어 주는 함수
*   @param s_   토큰으로 자를 문자열 
*   @param k_   기준으로 할 문자열 
*   @return vector<string> 잘려진 문자열 
*   문자열을 받아 임의의 문자열을 기준으로 토큰을 자른 후 
*   vector<string>으로 반환하는 함수 
*/
vector<string> strTok(string s_, string k_){
    vector<size_t> tokLocation = {0};
    vector<string> tok;
    
    int n;
    for(n=1;; n++){
        tokLocation.push_back(s_.find(k_, tokLocation[n-1]+1));
        if(tokLocation[n] == std::string::npos)
            break;
    }
    
    for(auto i=tokLocation.begin(); (i+1)!=tokLocation.end(); i++){
        if(i != tokLocation.begin())
            tok.push_back(s_.substr(*i+k_.size(), *(i+1) - *i-k_.size()));
        else
            tok.push_back(s_.substr(*i, *(i+1) - *i));
    }
    return tok;
}

bool checkString(string s_){
    if(s_[0] >= 'A' && s_[0] <= 'Z' ||
       s_[0] >= 'a' && s_[0] <= 'z' )
        return 0;
    else
        return 1;
}
struct Variable{
    string name;
    int value;
    
    bool operator!=(Variable &T){
        return (this->value != T.value || this->name != T.name);
    }
    bool operator==(Variable &T){
        return (this->value == T.value || this->name == T.name);
    }
};

int main() {
    string s;
	cin >> s;
    vector<string> token = strTok(s, "&&");

    for(auto i : token){
        cout << i << " ";
    }
    vector<Variable> var;
    vector<string> o_same;
    for(auto i : token){
        if(i.find("==")){
            o_same = strTok(i, "==");
            if(checkString(o_same[1])){
                Variable v_temp;
                v_temp.value = atoi(o_same[1].c_str());
            }
        }
        if(i.find("!=")){
            o_same = strTok(i, "==");

        }
    }
	return 0;
}