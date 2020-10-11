#include <string>   // Level1_ 체육복 [그리디]
#include <vector>

#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n+1, 1);
    int idx = 0;

    for(int i=0; i<lost.size(); i++){
        student[lost[i]] -= 1;
    }

    for(int i=0; i<reserve.size(); i++){
        student[reserve[i]] += 1;
    }

    for(int i=1; i<=student.size(); i++){
        if(student[i] > 1){
            if( i -1 >= 0){
                if( student[i-1] < 1){
                    student[i-1] += 1;
                    student[i] -= 1;
                }
            }
        }
        else if(student[i] > 1){
            if( i +1 <= n){
                if( student[i+1] < 1){
                    student[i+1] += 1;
                    student[i] -= 1;
                }
            }
        } 
    }


    for(int i=1; i<=n; i++){
        if(student[i] >= 1) answer++;
    }
    return answer;
}

int main(){
    int n, lost_n, reserve_n;
    vector<int> lost, reserve;

    cin >> n>> lost_n >> reserve_n;

    for(int i=0; i<lost_n; i++){
        int k;
        cin >> k;
        lost.push_back(k);
    }
    for(int i=0; i<reserve_n; i++){
        int k;
        cin >> k;
        reserve.push_back(k);
    }

    cout << solution(n, lost, reserve);


    return 0;
}