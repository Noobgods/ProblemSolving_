#include <string>   // Level2_ H-Index []
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    int s = citations.size();
    for(int i=0; i < s; i++){
        if(citations[i] >= s - i && i <= s - i) {
            answer = s - i;
            break;
        }
    }
    return answer;
}

int main(){
    int n;
    cin >> n;
    vector<int> citations;

    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        citations.push_back(k);
    }

    cout << solution(citations);

    return 0;
}