#include<cstdio>	// 15874_CaesarCipher [규칙]
#include<iostream>
using namespace std;
int k, s;
int main(){
	scanf("%d %d\n", &k, &s);
	char r[100001];
	cin.getline(r, s+1);
	
	for(int i=0; r[i] !='\0'; i++){
		if(r[i] >= 'a' && r[i]<= 'z')
			r[i] = (r[i]-'a'+ k)%26 + 'a';
		else if(r[i] >= 'A' && r[i] <= 'Z')
			r[i] = (r[i]-'A'+ k)%26 + 'A';
		printf("%c", r[i]);
	}
	return 0;
}