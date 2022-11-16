#include<cstdio>	// 9375_패션왕 신해빈 [자료구조][조합]
#include<cstring>
struct clothes{
	char type[21];
	int count = 0;
};
int main(){
    int T;
	scanf("%d", &T);
	while(T--){		
		int n, r=0, s=1;
		clothes c[30];
		char cloth[21];

		scanf("%d", &n);
		for(int j=0; j<n; j++){
			scanf("%s %s", &cloth, &cloth);
			for(int i=0; i<=r; i++){
				if(i == r) { 
					strcpy(c[r].type, cloth);
					c[r++].count++; break;}
				if(strcmp(cloth, c[i].type) == 0){
					c[i].count++; break; 
				} 
			}
		}
		for(int i=0; i<r; i++)
			s = s * (1 + c[i].count);
		s-=1;
		printf("%d\n", s);
	}
	return 0;
}