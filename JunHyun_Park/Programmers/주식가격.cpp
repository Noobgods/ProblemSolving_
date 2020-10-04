#include <string>   // level2_ 주식가격 [스택]
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> stk;

    for(int i=0; i<prices.size(); i++){
        if(stk.empty()) stk.push(i);
        else {
            while(!stk.empty()){
                if(prices[stk.top()] > prices[i]){
                    answer[stk.top()] = i - stk.top();
                    stk.pop();
                }
                else break;
            }
            stk.push(i);
        }
    }

    while(!stk.empty()){
        answer[stk.top()] = prices.size() - stk.top() - 1;
        stk.pop();
    }

    return answer;
}