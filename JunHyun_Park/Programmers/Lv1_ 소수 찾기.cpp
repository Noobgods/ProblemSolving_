#include <string> // Level1_ 소수 찾기 [소수]
#include <vector>

using namespace std;

bool primes[1000001] = {true, true};
int solution(int n) {
    int answer = 0;

    for(int i=2; i*i<=n; i++){
        if(!primes[i]){
            for(int j= i+i; j<=n; j+=i){
                primes[j] = true;
            }
        }
    }
    
    for(int i=2; i<=n; i++){
        if(!primes[i]) {
            answer++;
        }
    }
    return answer;
}