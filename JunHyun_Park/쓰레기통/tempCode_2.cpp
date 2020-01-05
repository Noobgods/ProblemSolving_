#include<cstdio>	// 
int DP[101][10];
int S, N;

int UD(int length, int down, int up, int mid){
	if(up < mid ) up = mid;
	if(down > mid) down = mid;
	if(down < 0){ up++; down++;}
	if(up > 9) return 0;
	if(down > up) {int tmp = down; down = up; up = tmp;}
	if(length <= 1) return 10 - up;	
	return (UD(length-1, down, up, mid+1) + UD(length-1, down, up, mid-1)) % 1000000000;
}
int main(){
	scanf("%d", &N);

	for(int i = 0; i<10; i++){
		
	}
	S = UD(N,1,1,1);
	printf("%d", S);

	return 0;
}