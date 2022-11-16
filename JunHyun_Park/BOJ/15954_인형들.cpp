#include<cstdio>	// 15954_인형들 [수학]
#include<cmath>
#include<vector>
#include<float.h>
using namespace std;
int N,K;
long long allsum,allsub, A[501], S[501];
vector<long long> sum[501], ssm[501];
int main(){
	scanf("%d %d", &N, &K);

	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
		allsum += A[i];
		S[i] = A[i]*A[i];
		allsub += S[i];
	}
	ssm[0].push_back(allsub);
	sum[0].push_back(allsum);
	for(int i=0; i<=N-K; i++){
		if(i!=0) ssm[i].push_back(ssm[i-1].front()-S[i-1]);
		if(i!=0) sum[i].push_back(sum[i-1].front()-A[i-1]);
		for(int j=N-1; j>=K+i; j--){
			ssm[i].push_back(ssm[i].back() - S[j]);
			sum[i].push_back(sum[i].back() - A[j]);
		}
	}
	long double min = 12346789.0f;
	for(int i=0; i<=N-K; i++){
		for(int j=N-i; j>=K; j--){
			int k = N-j-i;
			long double V, ss = (long double)ssm[i][k], sm = (long double)sum[i][k];

			V = ss/j - sm/j*sm/j;
			V = sqrt(V);
			if(min > V) min = V;
		}
	}
	
	printf("%.11Lf", min);
	return 0;
}