#include<cstdio>	//11404_플로이드 [플로이드워셜알고리즘] 
using namespace std;
#define MAX 100000001

int bus[101][101];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			bus[i][j] = MAX;
		}
	}

	for(int i=0; i<m; i++){
		int x, y, l;
		scanf("%d %d %d", &x, &y, &l);
		
		bus[x][y] = bus[x][y] < l ? bus[x][y] : l;
	} 

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(bus[i][j] > bus[i][k] + bus[k][j]){
                    bus[i][j] = bus[i][k] + bus[k][j];
				}
			}
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if (i == j || bus[i][j] == MAX) printf("0 ");
			else printf("%d ", bus[i][j]);
		}
		printf("\n");
	}

	return 0;
}