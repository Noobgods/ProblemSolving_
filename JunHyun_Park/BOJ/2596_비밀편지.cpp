#include<cstdio>	// 2596_비밀편지 [문자열처리]
#include<cstring>
int N;
char A[8][7] = {"000000",
	 "001111",
	 "010011",
	 "011100",
	 "100110",
	 "101001",
	 "110101",
	 "111010"},
	 result[11];
	
char check(char* a, char *s, char c){
	bool allowedNum = true;
	for(int i=0; i<6; i++){
		if(a[i] == s[i]);
		else if(allowedNum) allowedNum = false;
		else return 0;
	}
	return c;
}
int main(){
	scanf("%d\n", &N);
	for(int i=0; i<N; i++){
		char input[6];
		for(int j=0;;){
			scanf("%1c", &input[j++]);
			if(j>5) break;
		}
		for(char j='A'; j<='H'; j++){
			if(result[i] == 0) 
				result[i] = check(A[j-'A'], input, j);
		}
		if(result[i] == 0){
			printf("%d",i+1);
			return 0;
		}
	}
	printf("%s", result);
	return 0;
}