#include<cstdio>	// 4796 캠핑 [그리디]

int main(){
	for(int i=1; ;i++){
		int L, P, V;
		scanf("%d %d %d",&L, &P, &V);

		if((L|P|V)== 0) break;

		int r = (V/P)* L;
		int answer = (V - (V/P)*P);

		if(answer >= L) answer = L;
		else answer %= L;
		
		printf("Case %d: %d\n",i, answer+r);
	}

	return 0;
}