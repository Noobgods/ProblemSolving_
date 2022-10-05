#include <cstdio>	//6198_옥상정원꾸미기 [스택]
#include <stack>
#include <iostream>
using namespace std;

long long int result;
int main(){
	stack<pair<int,int>> s;
	int N;

	scanf("%d", &N);
	
	for(int i=1; i<=N; i++){
		int top;
		scanf("%d", &top);

		while(!s.empty() && s.top().first <= top){
			result += i - s.top().second - 1;
			s.pop();
		}
		
		s.push(make_pair(top, i));
	}
	while(!s.empty()){
		result += N - s.top().second;
		s.pop();
	}

	printf("%lld", result);
}