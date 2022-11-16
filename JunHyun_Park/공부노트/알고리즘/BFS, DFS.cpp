#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 1020

bool chk[MAX];
void dfs(int v);
void bfs(int v);
int n, m, v;    // 정점의 갯수, 간선 갯수, 탐색 시작 번호
int arr[MAX][MAX];
queue<int> q;

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

// DFS는 후입선출인 스택, 재귀를 사용함
void dfs(int v){
	chk[v] = true;  // 체크
	printf("%d ", v);   // 출력
	for (int i = 1; i <= n; i++) // 현재 위치에서 연결되어 있는 노드 너비 순회
		if (arr[v][i] == 1 && !chk[i])  // 연결되어 있는 노드 중 방문안한 노드 방문
			dfs(i); // 연결되어 있는 노드부터 깊이 순회
}

// BFS는 선입선출인 큐를 사용함
void bfs(int v){
	chk[v] = true;  // 첫 방문 체크
	q.push(v);      // 첫 방문 푸쉬
	int now;
	while (!q.empty()){     // 연결되어 있는 곳 모두 방문 할때까지 작동함
		now = q.front();    // 방문한것과 연결되어 있는 것을 확인 저장
		printf("%d ", now); // 출력
		q.pop();    // 볼일 봤으니 팝
		for (int i = 1; i <= n; i++)    // 너비 순회
			if (arr[now][i] == 1 && !chk[i]){     // 연결되어 있는 노드 중 방문안한 노드 방문
				chk[i] = true;      // 큐에 넣은 것 체크
				q.push(i);      // 큐에 푸쉬 (깊이 순회 준비)
			}
	}
}