#include <string>	// Level3_ 줄 서는 방법 [수학] [구현]
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

long long fact[21] = {1, };
vector<int> solution(int n, long long k) {
    vector<int> answer;
	vector<int> v;
	for(int i=1; i<=n; i++){
		fact[i] = fact[i-1] * i;
		v.push_back(i);
	}
	k-=1;
	for(int i=1; i<=n; i++){
		int idx = k/fact[n-i];
		answer.push_back(v[idx]);
		v.erase(v.begin() + idx);
		k %= fact[n-i];
    }

    return answer;
}

// 입출력
int main(){
	int n;
	long long k;
	cin >> n >> k;

	for(auto i : solution(n, k)){
		cout << i << " ";
	}
}