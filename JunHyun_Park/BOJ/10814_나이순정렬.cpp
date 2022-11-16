#include<cstdio>    // 10814_나이순정렬 [정렬]
#include<algorithm>
using namespace std;
struct ACT{
    int id;
    char na[101];
};
ACT ac[100001], tc[100001];
int N;
bool compare(ACT x, ACT y){
    return x.id < y.id ? true : false;
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
        scanf("%d %s", &ac[i].id, ac[i].na);

    stable_sort(&ac[0], &ac[N], compare);
	
	for(int i=0; i<N; i++)
		printf("%d %s\n", ac[i].id, ac[i].na);

	return 0;
}