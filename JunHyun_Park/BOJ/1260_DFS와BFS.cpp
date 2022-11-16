#include <cstdio>   // 1260_DFS와BFS [DFS], [BFS]
#include <queue>
#include <string.h>
using namespace std;

#define MAX 1020

bool chk[MAX];
void dfs(int v);
void bfs(int v);
int n, m, v;
int arr[MAX][MAX];
queue<int>q;
int main(){
	int a, b;
	scanf("%d %d %d", &n ,&m, &v);
	for (int i = 0; i < m; i++)	{
		scanf("%d %d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
	}
	dfs(v);
	memset(chk, false, MAX);
	printf("\n");
	bfs(v);
	return 0;
}

void dfs(int v){
	chk[v] = true;
	printf("%d ", v);
	for (int i = 1; i <= n; i++)
		if (arr[v][i] == 1 && !chk[i])
			dfs(i);
}

void bfs(int v){
	chk[v] = true;
	q.push(v);
	int now;
	while (!q.empty()){
		now = q.front();
		printf("%d ", now);
		q.pop();
		for (int i = 1; i <= n; i++)
			if (arr[now][i] == 1 && !chk[i]){
				chk[i] = true;
				q.push(i);
			}
	}
}