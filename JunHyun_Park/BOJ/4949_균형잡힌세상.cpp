#include<iostream>  // 4949_±ÕÇüÀâÈù¼¼»ó [½ºÅÃ]
#include<string>
using namespace std;

struct bracket{
    char s[101];
    int top_=-1;
    int pop(){
        if(top_ == -1) return 0;
        return s[top_--];
    }
    void push(char n){
        s[++top_] = n; 
    }
    int top(){
        if(top_ == -1) return 0;
        return s[top_];
    }
    bool is_correct(const char c);
    void reset(){
        top_ = -1;
    }
};

bool bracket::is_correct(const char c){
    char k;
    if(this->top() == 0) return false;
    if(c == ')') k = '(';
    if(c == ']') k = '[';

    if(this->top() == k) {
        this->pop();
        return true;
    }
    else return false;
    
}

int main(){
    int N;
    bracket S;
    for(;;){
        bool f=true;
        string s;
        std::getline(std::cin, s);
        if(s == ".") return 0;
        for(auto k : s){
            if(f){
                if(k == '(' || k == '[')
                    S.push(k);
                if(k == ')' || k == ']') 
                    f = S.is_correct(k);
            }
            else break;
        }
        if (!f || S.top()) cout << "no" << endl;
        else cout << "yes" << endl;
        S.reset();
    }
    return 0;
}