#include<cstdio>	// 1010_다리놓기 [DP]
int n,m,T;
int dp(int x,int y){
	if(x==y)return 1;
	if(x==1)return y;
	return dp(x-1,y-1)+dp(x,y-1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		printf("%d\n",dp(n,m));
	}
}