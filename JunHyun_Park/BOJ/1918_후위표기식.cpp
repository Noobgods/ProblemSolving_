#include <iostream>     // 1918_후위표기식 [스택]
#include <stack>
#include <vector>
#include <string>
using namespace std;

int checkLevel(char c){
    if(c == ')') return 4;
    if(c == '(') return 3;
    if(c == '+' || c == '-') return 2;
    if(c == '*' || c == '/') return 1;

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    stack<char> stk;
    vector<char> ps;
    for(auto c : str){
        if(checkLevel(c) < 0){
            ps.push_back(c);
        }            
        else {
            if(c == '(') {
                stk.push(c);
            }
            else {
                while(!stk.empty() && checkLevel(stk.top()) <= checkLevel(c)){
                    if(stk.top() == '('){
                        stk.pop();
                        break;
                    }
                    ps.push_back(stk.top());
                    stk.pop();
                    
                }
                if(c != ')'){
                    stk.push(c);
                }
            }
        }
    }
    while(!stk.empty()){
        if(stk.top() != '('){
            ps.push_back(stk.top());
        }
        stk.pop();
    }
    for(auto v : ps)
        cout << v;

    return 0;
}