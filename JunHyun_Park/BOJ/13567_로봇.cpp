#include<cstdio>	// 13567 로봇 [구현]
#include<cstring>
int x,y,M,N,r=1000; bool o;
int main(){
	scanf("%d", &M);
	for(scanf("%d", &N); N--;){
		char s[5];
		scanf("%s", &s);

		int c;
		if(strcmp(s, "TURN")==0){
			scanf("%d", &c);
			if(c) r--;
			else r++;
		}
		if(strcmp(s, "MOVE")==0){
			scanf("%d", &c);
			if(r%4==0) x+=c;
			if(r%4==1) y+=c;
			if(r%4==2) x-=c;
			if(r%4==3) y-=c;
			if(x<0 || y<0 || x>M || y>M) o =true;
		}
	}
	if(o) printf("-1");
	else printf("%d %d", x, y);
	return 0;
}