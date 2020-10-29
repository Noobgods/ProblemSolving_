#include <string>	// Level3_ 여행경로 [DFS]
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

bool visited[100001];
vector<vector<string>> path;

bool cmp(const vector<string>& a, const vector<string>& b){
	for(int i=0; i<a.size(); i++){
		if (a[i] != b[i]) return a[i] < b[i]; 
	}
	return true;
}

void dfs(const vector<pair<string, string>> v, int n, string s, vector<string>& answer, int size){
	if(n == size){
		path.push_back(answer);
	}

	for (int i =0; i<size; i++){
		string target;
		if(v[i].first == s)
		if(!visited[i]){
			visited[i] = true;
			target = v[i].second;
			answer[n+1] = target;
			dfs(v, n+1, target, answer, size);
			visited[i] = false;
		}
	}
}
vector<string> solution(vector<vector<string>> tickets) {
	int size = tickets.size();
	vector<string> answer(size+1);
	vector<pair<string, string>> pass;

	for(int i=0; i<size; i++){
		pass.push_back(make_pair(tickets[i][0], tickets[i][1]));
	}
	
	answer[0] = "ICN";
	dfs(pass, 0, "ICN", answer, size);

	sort(path.begin(), path.end(), cmp);

	answer = path[0];
    return answer;
}

int main(){
	vector<vector<string>> tickets;

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		vector<string> v;

		for(int j=0; j<2; j++){
			string s;
			cin >> s;
			v.push_back(s);
		}

		tickets.push_back(v);
	}

	for(auto i : solution(tickets)){
		cout << i << " ";
	}


	return 0;
}