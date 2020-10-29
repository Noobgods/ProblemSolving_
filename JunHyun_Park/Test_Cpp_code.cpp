#include<cstdio>	// 15650_N과M(2) [백트래킹]
int n,m;
bool v[9];
char a[18]="0 0 0 0 0 0 0 0\n\0";
void f(int x,int y){
	if(x==m)printf("%s",a);
	else for(int i=y;i<n;i++)
		if(!v[i]){
			v[i]=true;
			a[x*2]=48+i+1;
			f(x+1, i+1);
			v[i]=false;
		}
}
int main(){
	scanf("%d %d",&n,&m);
	a[m*2]=10;
	a[m*2+1]=0;
	f(0,0);
	return 0;
}