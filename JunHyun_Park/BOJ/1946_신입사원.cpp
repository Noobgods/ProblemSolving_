#include <cstdio>	// 1946_신입사원 [그리디]
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int T;
	
	scanf("%d", &T);
	while(T--){
		int N, answer=1;
		scanf("%d", &N);

		int arr[N+1];

		for(int i=0; i<N; i++){
			int input1, input2;
			scanf("%d %d", &input1, &input2);
			arr[input1] = input2;
		}

		int best = arr[1];
		for(int i=2; i<=N; i++){
			if(best > arr[i]){
				best = arr[i];
				answer++;
			}
		}
		
		printf("%d\n", answer);
	}

	return 0;
}