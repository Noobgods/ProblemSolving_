#include <string>   // Level2_ 구명보트 [그리디]
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int minPoint = people.size()-1;
    sort(people.begin(), people.end(), greater<int>());

    for(int i=0; i<=minPoint; i++){
        if(people[minPoint] + people[i] <= limit){
            minPoint--;
        }
        answer++;
    }
    return answer;
}

int main(){
    int n;
    cin >> n;
    vector<int> people;

    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        people.push_back(k);
    }
    int limit;
    cin >> limit;

    cout << solution(people, limit);

    return 0;
}