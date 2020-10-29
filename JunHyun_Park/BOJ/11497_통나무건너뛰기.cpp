#include <cstdio>	// 11497_통나무건너뛰기 [그리디]
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int N, M = 0;
		vector<int> arr;
		scanf("%d", &N);

		for(int i=0; i<N; i++){
			int k;
			scanf("%d", &k);
			arr.push_back(k);
		}

		sort(arr.begin(), arr.end());

		for(int i=0 ;i<N-2; i++){
			M = max(arr[i+2] - arr[i], M); 
		}
		M = max(arr[N-1]- arr[N-2], M);

		printf("%d\n", M);
	}

	return 0;
}