#include <string> // Level2_ ?? ?? [dfs]
#include <vector>

#include <iostream>

using namespace std;

int answer = 0;

void dfs(int n, int sum, int target, vector<int> numbers){
    if(n == numbers.size()) {
        if(sum == target) answer++;
        return;
    }
    dfs(n+1, sum+numbers[n], target, numbers);
    dfs(n+1, sum-numbers[n], target, numbers);

}
int solution(vector<int> numbers, int target) {
    dfs(0, 0, target, numbers);
    return answer;
}

int main(){
    vector<int> numbers;
    int n, answer, target;
    cin >> n >> target;

    for(int i=0; i<n; i++){
        int k=0;
        cin >> k;
        numbers.push_back(k);
    }
    answer = solution(numbers, target);

    cout << answer << endl;

    return 0;
}