#include <string>	// Level2_ 프린터 [큐]
#include <vector>
#include <queue>

#include <iostream>
using namespace std;
#define pii pair<int, int>

int solution(vector<int> priorities, int location) {
    int answer = 1;
	priority_queue<int> pq;
	queue<pii> q;
	for(int i=0; i<priorities.size();i++){
		pq.push(priorities[i]);
		q.push(make_pair(priorities[i], i));
	}

	for(int i=9; i>=1; i--){
		int j=0;
		while(pq.top() == i){
			j++;
			pq.pop();
			if(pq.empty()) break;
		}

		for(int k=0; k<j; ){
			pii s = q.front();
			if(s.first != i) q.push(s);
			else {
				if(s.second == location) return answer;
				answer++;
				k++;
			}
			q.pop();
		}
	}

	return answer;
}

// IO
int main(){
	int n, location;
	cin >> n >> location;

	vector<int> priorities;
	for (int i=0; i<n; i++){
		int k;
		cin >> k;
		priorities.push_back(k);
	}	

	cout << solution(priorities, location);
	
	return 0;
}