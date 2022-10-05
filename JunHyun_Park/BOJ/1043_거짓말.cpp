#include <cstdio>	//1043_°ÅÁþ¸» [±×·¡ÇÁ Å½»ö]
using namespace std;

bool node[51][51], visit[51];
int party[51][51], know[51];
int N, M, K, r = 0;

void f(int n){
	for(int i=1; i<=N; i++){
		if(!visit[i] && node[n][i]){
			visit[i] = true;
			f(i);
		}
	}
}
int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<K; i++){
		int index;
		scanf("%d", &index);
		know[i] = index;
	}

	for(int i =0; i<M; i++){
		scanf("%d", &party[i][0]);

		for(int j=1; j<=party[i][0]; j++){
			scanf("%d", &party[i][j]);
		}
		for(int j=1; j<=party[i][0]; j++){
			for(int k=1; k<=party[i][0]; k++){
				node[party[i][j]][party[i][k]] = true;
			}
		}
	}

	for(int i=0; i<K; i++){
		if(!visit[know[i]]){
			visit[know[i]] = true;
			f(know[i]);
		}
	}
	for(int i=0; i<M; i++){
		if(!visit[party[i][1]]) r++;
	}

	printf("%d", r);
	return 0;
}