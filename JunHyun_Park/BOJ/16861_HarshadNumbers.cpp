#include<cstdio>	// 16861 HarshadNumbers [문자열], [수학]
int n, h;
char s[11];
int main(){
	scanf("%d", &n);
	
	do{
		sprintf(s, "%d", n++);
		h = 0;
		for(int i=0; s[i] != '\0'; i++){
			h += (s[i]-'0');
		}
	}while((n-1)%h != 0);
	printf("%d", n-1);
	return 0;
}