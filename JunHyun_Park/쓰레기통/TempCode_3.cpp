#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp1(const pair<pair<int,int>,bool>& a, const pair<pair<int,int>,bool>& b){
	return a.first.first < b.first.first;
}
bool cmp2(const pair<pair<int,int>,bool>& a, const pair<pair<int,int>,bool>& b){
	return a.first.second < b.first.second;
}

int main(){
	int T;
	
	scanf("%d", &T);
	while(T--){
		int N, answer=0;
		scanf("%d", &N);

		vector<pair<pair<int, int>, bool>> arr;

		for(int i=0; i<N; i++){
			int input1, input2;
			scanf("%d %d", &input1, &input2);
			arr.push_back(make_pair(make_pair(input1, input2), true));
		}

		sort(arr.begin(), arr.end(), cmp1);

		for(int i=0; i<N-1; i++){
			if(arr[i].second)
			for(int j=i+1; j<N; j++){
				if(arr[j].second)
				if(arr[i].first.second < arr[j].first.second){
					arr[j].second = false;
				}
			}
		}
		
		sort(arr.begin(), arr.end(), cmp2);

		for(int i=0; i<N-1; i++){
			if(arr[i].second)
			for(int j=i+1; j<N; j++){
				if(arr[j].second)
				if(arr[i].first.first < arr[j].first.first){
					arr[j].second = false;
				}
			}
		}
		
		for(int i=0; i<N; i++){
			if(arr[i].second){
				answer++;
			}
		}
		
		printf("%d\n", answer);
	}

	return 0;
}