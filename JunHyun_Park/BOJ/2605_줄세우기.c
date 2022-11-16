#include<cstdio>	// 2605_줄세우기 [규칙]
#include<stdlib.h>

void swap(int num, int *ln);
int num ,i,j;

int main(){
	int *out_ln;
	int in_ln;

	scanf("%d",&num);

	out_ln = (int*)calloc(num, sizeof(int));

	for(i=0; i<num; i++){
		scanf("%d",&in_ln);
		out_ln[i]=i+1;
		for(j=i; 0<in_ln; in_ln--){
			swap(j, out_ln);
			j--;
		}
	}
	for(i=0; i<num; i++){
		printf("%d ",out_ln[i]);
	}
	
	free(out_ln);
	return 0;
}

void swap(int num,int *ln){
	int tmp;

	tmp= ln[num-1];
	ln[num-1] = ln[num];
	ln[num] = tmp;
}