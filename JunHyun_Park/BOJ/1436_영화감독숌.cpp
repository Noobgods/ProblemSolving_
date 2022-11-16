#include<cstdio>    // 1436_영화감독숌 [브루트포스]
int N;
bool is666(int n){
    if(n%1000 == 666) return true;
    else if((n%10000)/10 == 666) return true;
    else if((n%100000)/100 == 666) return true;
    else if((n%1000000)/1000 == 666) return true;
    return false;
}
int main(){
	int k = 665;
    scanf("%d", &N);
    for(int i=0; i<N;)
        if(is666(++k)) i++;
	printf("%d\n", k);
	return 0;
}