#include<cstdio>	// 11070_피타고라스기댓값 [수학]
int T, n, m, a,b,p,q;
int main(){
	scanf("%d", &T);
	while(T--){
		int S[1001]={0}, A[1001]={0}, min = 1000, max = 0;
		scanf("%d %d", &n, &m);
		while(m--){
			scanf("%d %d %d %d", &a,&b,&p,&q);
			S[a] += p;	S[b] += q;
			A[a] += q;	A[b] += p;
		}
		for(int i=1; i<=n; i++){
			if(S[i]!=0)
				S[i] = (float)(S[i]*S[i])/(float)(S[i]*S[i]+A[i]*A[i])*1000.0f;
			if(max < S[i]) max = S[i];
			if(min > S[i]) min = S[i];
		}
		printf("%d\n%d\n",max, min);
	}
	return 0;
}