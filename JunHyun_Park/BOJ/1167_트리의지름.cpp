#include<cstdio>	//1167_트리의 지름 [DFS], [트리]
#include<vector>
using namespace std;

vector<pair<int, int>> tree[100001];
bool visits[100001];
int largest = 0;
int temp = 0;

bool isLeaf(int n){
	if(tree[n].size() == 1)
		return true;
	return false;
}

void dfs(int n, int length){
	if(length > largest) {
		largest = length;
		temp = n;
	}
	for(auto node : tree[n]){
		if(!visits[node.first]){
			visits[node.first] = true;
			dfs(node.first, length + node.second);
			visits[node.first] = false;
		} 
	}
}

int main(){
	int V;
	scanf("%d", &V);

	for(int i = 0; i<V; i++){
		int N, A, B; 
		scanf("%d", &N);
		
		while(1) {
			scanf("%d", &A);
			if (A<0) break;
			scanf("%d", &B);
			
			tree[N].push_back(make_pair(A,B));			
		}
	}

	for(int i=1; i<=V; i++){
		if(isLeaf(i)){
			visits[i] = true;
			dfs(i, 0);
			visits[i] = false;

			visits[temp] =true;
			dfs(temp, 0);
			visits[temp] = false;
			
			break;
		}
	}

	printf("%d", largest);
	return 0;
}