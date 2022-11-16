#include<cstdio>	// 2812_크게만들기 [그리디] [스택]
#include<stack>
using namespace std;

int main(){
	int K, N, i;
	scanf("%d %d\n",&N, &K);

	char number[500001], answer[500001];
	scanf("%s", number);

	stack<char> s; int poped=0;
	s.push(number[0]);

	for(i=1;i<N && poped<K; i++){
		if(s.top() >= number[i]){
			s.push(number[i]);
		}
		else{
			while(!s.empty() && s.top() < number[i] && poped < K){
				poped++;
				s.pop();
			}
			
			s.push(number[i]);
		}
	}
	while(poped < K){
		s.pop();
		poped++;
	}
	int l = s.size();
	for(int j=0; j<N-K; j++){
		if(!s.empty()){
			answer[l-j-1] = s.top();
			s.pop();
		}
		else{
			answer[j] = number[j+K]; 
		}
	}
	printf("%s\n", answer);
	return 0;
}