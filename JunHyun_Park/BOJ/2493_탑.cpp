#include <cstdio>	// 2493_е╬ [╫╨ец]
#include <stack>
#include <iostream>
using namespace std;

int main(){
	stack<pair<int,int>> s;
	string str = "";
	int N;

	scanf("%d", &N);
	
	for(int i=1; i<=N; i++){
		int top;
		scanf("%d", &top);
		
		while(!s.empty() && s.top().first < top)
			s.pop();
		
		if (s.empty())
			str += "0 ";
		else
			str += to_string(s.top().second) + ' ';
		
		s.push(make_pair(top, i));
	}
	printf("%s", str.c_str());
}