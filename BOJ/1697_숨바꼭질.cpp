#include<cstdio>	// 1697_숨바꼭질 [BFS]
#include<queue>
using namespace std;

int N,K, d[2]{1,-1}, R;
bool v[200001];
int f(int n){
	queue<pair<int,int>> q;
	q.push({n,0});

	int x, t;
	while(!q.empty()){
		x = q.front().first;
		t = q.front().second;
		if(x == K) return t;
		q.pop();
		for(int i=0;i<3; i++){
			int dx;
			if(i==2) dx = x*2;
			else dx = x+d[i];
			if(dx<0 || dx>=100001) continue;
			else if(!v[dx]){
				v[dx] = true;
				q.push({dx, t+1});
			}
		}
	}
	return t;
}
int main(){
	scanf("%d %d", &N, &K);
	
	printf("%d", f(N));
	return 0;
}