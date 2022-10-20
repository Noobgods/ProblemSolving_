#include <iostream>
#include <stack>
#include <string>
using namespace std;

int checkLevel(char c){
    if(c == '(') return 1;
    if(c == ')') return 2;
    if(c == '*' || c == '/') return 3;
    if(c == '(' || c == ')') return 4;

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    cout << str;

    stack<char> stk;
    for(int i = 0; i<str.size(); i++){
        char c = str[i];    
        if(checkLevel(c) < 0){        
           cout << c;
        }
        else{
            if(checkLevel(c) == 1){
                stk.push(c);
            }
            else {
                if(checkLevel(c) == 2){
                    while(stk.top() != '('){
                        cout << stk.top();
                        stk.pop();
                    }
                    stk.pop();
                }
                else{
                    if(checkLevel(c) == 3){
                        while(checkLevel(stk.top()) <= 3){
                            cout << stk.top();
                            stk.pop();
                        }
                    }
                    else {
                        while(checkLevel(stk.top()) <= 4){
                            cout << stk.top();
                            stk.pop();
                        }
                    }
                }
            }
        }
    }

    return 0;
}