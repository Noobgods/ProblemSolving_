#include<cstdio>	// 6603_로또 [백트래킹]
int N, nl[13], s[6];
bool bl[13] ={false};
void f(int x, int y){
	if(x == 6) {
		for(int i=0;i<6; i++){
			printf("%d ",s[i]);
		}
		printf("\n");
		return;
	}
	for(int i=y; i<N; i++){
		if(!bl[i]){
			bl[i] = true;
			s[x]=nl[i]; 
			f(x+1, i+1);
			bl[i] = false;
		}
	}
}
int main() {
	while(1){
		scanf("%d", &N);
		if(N==0) break;
		for(int i=0;i<N; i++)
			scanf("%d", &nl[i]);
		f(0, 0);
		printf("\n");
	}
	return 0;
}