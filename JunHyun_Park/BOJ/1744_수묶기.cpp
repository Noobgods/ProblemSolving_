#include<cstdio>	// 1744_수묶기 [그리디]
#include<algorithm>
using namespace std;

int main(){
	int N, answer= 0; 
	int arr[10001];

	scanf("%d", &N);

	for(int i=0;i<N; i++){
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr+N);

	for(int i=0; i<N; i++){
		if(arr[i] <= 0 && arr[i+1] <= 0 && i+1<N){
			answer += arr[i] * arr[i+1];
			i++;
		}
		else if (arr[i] < 0) answer += arr[i];
		else break;
	}
	for(int i=N-1; i>=0; i--){
		if(arr[i] > 0 && arr[i-1] > 1 && i-1 >= 0){
			answer += arr[i] * arr[i-1];
			i--;
		}
		else if (arr[i] > 0) answer += arr[i];
		else break;
	}

	printf("%d", answer);

	return 0;
}