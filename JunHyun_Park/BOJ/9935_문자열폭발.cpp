#include <cstdio>   //9935_문자열폭발 [스택]
#include <stack>
#include <iostream>
using namespace std;

int main(){
    stack<int> S;
    char str[1000001];
    char boom[1000001];
    string result = "";

    scanf("%s %s", str, boom);
    int l;
    for(l=0; boom[l]!='\0'; l++);
    for(int i=0; str[i] != '\0';i++){
        if (boom[0] == str[i])
            S.push(1);

        else if (!S.empty() && boom[S.top()] == str[i])
            S.top()++;

        else while(!S.empty()) S.pop();
        result += str[i];

        if(!S.empty() && S.top() == l) {
            S.pop();
            result.erase(result.size()-l, l);
        }
    } 

    if(result.size() == 0)printf("FRULA");
    else printf("%s", result.c_str());

    return 0;
}