#include<cstdio>	// 11650_좌표정렬하기 [정렬]
int p[100001][2], n;

void swap(int x, int y, int i){
	int t = p[x][i];
	p[x][i] = p[y][i];
	p[y][i] = t;
}

void sort(int first, int last, int s){
	int i= first, j=last;
	int idx = p[(first + last) /2][s];
	while(i<=j){
		while(p[i][s] < idx) i++;
		while(p[j][s] > idx) j--;
		if(i<=j) {
			if(s==0)
				swap(i, j, 0);
			swap(i++, j--, 1);
		}
	}
	
	if(first < j) sort(first, j, s);
	if(i < last) sort(i, last, s);
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n;i++)
		scanf("%d %d", &p[i][0], &p[i][1]);
	
	sort(0, n-1, 0);
	
	int k = 0, j=0;
	for(int i=0; i<n; i++){ 
		if(p[k][0] != p[i][0]) {
			if(k < i)
				sort(k, i-1, 1);
			k = i;
		}
		if(i == n-1 && k < i) sort(k, i, 1);
	}
	
	for(int i=0; i<n;i++)
		printf("%d %d\n", p[i][0], p[i][1]);
	
	return 0;
}