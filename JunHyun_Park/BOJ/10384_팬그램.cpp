#include<iostream>	// 10384 팬그램 [구현]
#include<cstdio>
using namespace std;
char s[2000], A[26], r;
int T; 
int main(){
	scanf("%d\n", &T);
	for(int t=1; t<=T; t++){
		r = 100;
		for(int i=0; i<26; i++)	A[i] = 0;
		cin.getline(s, 2000);
		for(int i=0; s[i] != '\0'; i++){
			if(s[i]>96 && s[i]<123)
				A[s[i]-97]++;
			if(s[i]>64 && s[i]<91)
				A[s[i]-65]++;
		}
		for(int i=0; i<26; i++) {
			if(A[i]<1) {r = 0; break;}
			if(A[i]<r) r = A[i];
		}
		printf("Case %d: ", t);
		if(r > 2) printf("Triple pangram!!!\n");
		else if(r > 1) printf("Double pangram!!\n");
		else if(r > 0) printf("Pangram!\n");
		else printf("Not a pangram\n");
	}
	return 0;
}