#include<cstdio>	// 1010_다리놓기 [DP]
int n,m,T,DP[31][31] = {0,};
int dp(int x,int y){
	if(x==y)return 1;
	if(x==1)return y;
    if(DP[x][y] == 0){
        return DP[x][y] = dp(x-1,y-1)+dp(x,y-1);
    }
	else
    {
        return DP[x][y]; 
    }
    
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		printf("%d\n",dp(n,m));
	}
}