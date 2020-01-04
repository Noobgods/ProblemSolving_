#include <iostream>     // 2504_괄호의 값 [스택]
#include <stack>
using namespace std;
char s[40], c;
stack<char> st;
stack<char> op;
stack<int> ca;
bool cal(char _c){
    int x, y;
    if(_c == '+'){
        x = ca.top();
        ca.pop();
        y = ca.top();
        ca.pop();                            
        ca.push(x + y);
        return true;
    }
    else if(_c == '*'){
        x = ca.top();
        ca.pop();
        y = ca.top();
        ca.pop();         
        ca.push(x * y);
        return true;
    }
    else return false;
}
int main(){
    cin >> s;
    for(int i=0; s[i] != '\0'; i++){
        c = s[i];    
        if( c == '(' || c == '[') {
            if(i>0){
                if(s[i-1] == ')' || s[i-1] == ']'){
                    while(!op.empty() && op.top() == '+'){
                        cal('+');
                        op.pop();
                    }
                    op.push('+');
                }
                if(s[i-1] == '(' || s[i-1] == '[')
                    op.push('(');
            }
            if(c == '(') st.push('(');
            if(c == '[') st.push('[');
        }
        else if(st.empty() && (c == ')' || c == ']')) {cout << "0"; return 0;}
        else if( (c == ')' && st.top() == '(') || (c == ']' && st.top() == '[')){
            if(i>0){
                if(s[i-1] == ')' || s[i-1] == ']'){
                    while(!op.empty() && (op.top() == '+' || op.top() == '*')){
                        cal(op.top());
                        op.pop();
                    }

                    if(c == ')') ca.push(2);
                    if(c == ']') ca.push(3);
                    op.push('*');
                
                    while(!op.empty()){
                        cal(op.top());
                        op.pop();
                        if(op.top() == '(')
                            op.pop(); break;
                    }
                }
                else {   
                    if(c == ')') ca.push(2);
                    if(c == ']') ca.push(3);
                }
            }
            st.pop();
        }
        else { c= -1; break;}
    }
    while(!op.empty() && c != -1){
        cal(op.top());
        op.pop();
    }
    if( c == -1 || !st.empty()) cout <<"0";
    else cout<< ca.top();
    return 0;    
}