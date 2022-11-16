#include<cstdio>	// 3486 AddingReversedNumbers [수학], [문자열]
#include<cstring>
#include<cstdlib>
int T, n_1, n_2;
char c_1[11], c_2[11];
void swap(char *c_1, char *c_2){
	char tmp = *c_1;
	*c_1 = *c_2;
	*c_2 = tmp;
}
void reverse(char* s){
	for(int i = 0; i<strlen(s)/2; i++){
		swap(&s[i], &s[strlen(s)-i-1]);
	}
}
int main(){
	for(scanf("%d", &T); T--;){
		scanf("%s %s", &c_1, &c_2);		
		reverse(c_1);
		reverse(c_2);
		n_1 = atoi(c_1) + atoi(c_2);
		sprintf(c_1, "%d", n_1);
		reverse(c_1);
		n_1 = atoi(c_1);
		printf("%d\n", n_1);
	}	
	return 0;
}
