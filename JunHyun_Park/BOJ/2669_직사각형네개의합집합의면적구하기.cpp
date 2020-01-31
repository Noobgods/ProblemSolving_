#include<cstdio>	// 2669_직사각형네개의합집합의면적구하기 [수학], [구현]
int N, S;
bool A[102][102];
int main(){
    for(int m=0; m++<4;){
		int x, y, dx, dy;
		scanf("%d %d %d %d",&x, &y, &dx, &dy);
		for(int i=x; i<dx; i++){
			for(int j=y; j<dy; j++){
				if(!A[i][j]) A[i][j] = true;
			}
		}
	}
	for(int i=0; i<=100; i++)
		for(int j=0; j<=100; j++)
			if(A[i][j]) S++;
	
	printf("%d",S);
	return 0;
}