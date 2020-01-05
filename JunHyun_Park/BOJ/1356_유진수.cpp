#include<cstdio>	// 1356_유진수 [수학]
char s[11];
int l;
int main(){
	scanf("%s", s);
	int i, j;
	for(i=0; s[i] !='\0'; i++)
		s[i] -= '0';
	l = i;	
	for(i=1; i<l; i++){
		int h=1, t=1;
		for(j=0; j<l; j++){
			if(j<i) h *= s[j];
			if(j>=i) t *= s[j];
		}
		
		if (h == t) {printf("YES"); return 0;}
	}
	printf("NO");
	return 0;
}