#include<cstdio>	// 14954 HAPPYNUMBER [수학]
int f(int n){
	char a[11];int r=0;
	sprintf(a,"%d",n);
	for(int i=0;a[i]!='\0';i++){
		int x=a[i]-'0';
		r+=x*x;
	}
	return r;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<20; i++){
		n=f(n);
		if(n==4||n==16||n==37||n==58||n==89||n==145||n==42||n==20){
			printf("UNHAPPY\n");
			break;
		}
		else if(n==1){
			printf("HAPPY\n");
			break;
		}
	}
	return 0;
}