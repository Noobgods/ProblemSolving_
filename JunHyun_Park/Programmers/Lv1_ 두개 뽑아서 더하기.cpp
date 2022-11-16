#include <string.h> // level1_ 두 개 뽑아서 더하기 [월간 코드 챌린지]
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    bool ans[201];
    memset(ans, 0, sizeof(ans));
    vector<int> answer;

	for(int i=0; i<numbers.size()-1; i++){
        for(int j=i+1; j<numbers.size(); j++){
            ans[numbers[i] + numbers[j]] = true;
        }
    }

    for(int i=0; i<=200; i++){
        if(ans[i]){
            answer.push_back(i);
        }
    }

    return answer;
}