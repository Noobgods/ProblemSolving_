#include <string>   // Level3_ 2xn 타일링 [수학]
#include <vector>

#include <iostream>

using namespace std;

int solution(int n) {
    int answer=0;

    if (n == 1) answer = 1;
    else if (n == 2) answer = 2;
    else
    for(int i=2, j=1, k=2; i<n; i++){
        answer = (j + k)%1000000007;
        j = k;
        k = answer;
    }

    return answer;
}

int main(){
    int n;
    cin >> n;

    cout << solution(n);
    return 0;
}