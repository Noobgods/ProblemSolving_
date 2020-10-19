#include <string>   // Level2_ 124 나라의 숫자 [구현]
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i= n; i>0;){
        answer.push_back(i%3 == 0 ? '4' : i%3 +'0');
        i = answer.back() == '4' ? i/3 -1 : i/3; 
    }
    reverse(answer.begin(), answer.end());
    return answer;
}