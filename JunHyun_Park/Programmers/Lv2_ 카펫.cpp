#include <string>   // Level2_ 카펫 [정렬]   
#include <vector>

#include <iostream>
using namespace std;


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown + yellow;

    int l=3, r=sum/3, m_l, m_r;
    while(l <= r){
        int b = r*2 + (l-2)*2;
        int y = (r-2)*(l-2);
        if( b==brown && y==yellow){
            m_l = l;
            m_r = r;
        }
        l++;
        r = sum/l;
    }
    
    answer.push_back(m_r);
    answer.push_back(m_l);

    return answer;
}

// 
int main(){
    int brown, yellow;
    cin >> brown >> yellow;

    solution(brown, yellow);
    return 0;
}