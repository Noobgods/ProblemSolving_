#include<cstdio> // 15897_잘못구현한에라토스테네스의체
long long int N,S;
int main(){
	int i,j=1, k_1=1, k_2=1;
	scanf("%d", &N);
	S = 0;
	for(i=1; i*i<N; i++){
		if(N%2){
			if(N%i == 0 && (N+1)%i ==0){
				S += (N+1)/i * k_1;
				k_1=1;
				S += ()
				k_2= i;
			}
		}
		else{
			if(N%i == 0){
				S += N/i * k_1;
				k_1=1;
			}
			else if((N-1)%i ==0){
				printf("+ (%d *%d)", (N/i+1), k_1);
				S += (N/i+1) * k_1;

				k_1=1;
			}
		}
		k_1++;
	}
	printf("%d", S);
	return 0;
}