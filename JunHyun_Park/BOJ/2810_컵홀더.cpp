#include <cstdio>	// 2810_ÄÅÈ¦´õ [±×¸®µğ]
#include <string>

using namespace std;

int main(){
	int N, answer=-1;
	scanf("%d", &N);

	char str[51];
	scanf("%s", str);

	for(int i=0; i<N; i++){
		if(str[i] == 'L'){
			answer++;
			i++;
		}
	}

	if(answer==-1) printf("%d",N);
	else printf("%d", N - answer);

	return 0;
}