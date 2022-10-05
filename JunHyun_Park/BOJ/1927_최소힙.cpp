#include<cstdio>	// 1927_최소힙 [우선순위큐]
#include<queue>
using namespace std;

struct cmp{
	bool operator()(int x, int y){
		return x > y ? true : false;
	}
};

int main(){
	priority_queue<int, vector<int>, cmp> pq;

	int N;
	scanf("%d", &N);
	
	while(N--){
		int x;
		
		scanf("%d",&x);

		if (x == 0){
			if(pq.empty() == true){
				printf("0\n");
			}
			else{
				printf("%d\n", pq.top());
				pq.pop();				
			}
		}
		else{
			pq.push(x);
		}
	}
}