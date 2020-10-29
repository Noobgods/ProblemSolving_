#include <cstdio>	// 11256_사탕 [그리디]
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int T,J,N, R, C;
	scanf("%d",&T);
	while(T--){
		priority_queue<int, vector<int>, less<int>> box;
		int answer= 0;
		scanf("%d %d",&J, &N);
		for(int i=0; i<N; i++){
			scanf("%d %d", &R, &C);
			box.push(R*C);
		}
		while(J > 0){
			J -= box.top();
			box.pop();
			answer++;
		}
		printf("%d\n", answer);
	}


	return 0;
}