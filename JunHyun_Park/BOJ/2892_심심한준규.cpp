#include <cstdio>   // 2892_심심한준규 [문자열처리]

int main(){
	int n, T;
	for(scanf("%d", &n); n--;){
		scanf("%x", &T);
		if(T<38) printf(".");
		else printf("-");
	}
	return 0;
}