#include<cstdio>	// 10797 10부제 [구현]
int N, R;
int main(){
	scanf("%d\n", &N);
	
	for(int i =0; i<5; i++){
		int t;
		scanf("%d", &t);
		if(t==N) R++;
	}
	printf("%d", R);
	return 0;
}
