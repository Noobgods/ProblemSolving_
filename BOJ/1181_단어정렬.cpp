#include<cstdio>	// 1181_단어정렬 [정렬]
#include<cstring>
int n;
char s[20002][55];
int sc(char* x, char *y){
	if(*x == '\0' || *y =='\0') return 0;
	if(*x == *y) return sc(x+1, y+1);
	if(*x < *y) return -1;
	if(*x > *y) return 1;
}
void swap(char* x,char* y){
	char t[55];strcpy(t, x);strcpy(x, y);strcpy(y, t);
}
void sort(int first, int last){
	int i= first, j=last;
	char idx[55];
	strcpy(idx, s[(first + last) /2]);
	while(i<=j){
		while(sc(s[i],idx)<0) i++;
		while(sc(s[j],idx)>0) j--;
		if(i<=j)
			swap(s[i++], s[j--]);
	}
	if(first < j) sort(first, j);
	if(i < last) sort(i, last);
}
int main(){	
	scanf("%d ", &n);
	for(int i=0;i<n; i++){
		scanf("%s",s[i]+1);
		s[i][0] = strlen(s[i]+1);
	}
	sort(0, n-1);
	printf("%s\n", s[0]+1);
	for(int i=1;i<n;i++)
		if(strcmp(s[i-1], s[i]))	printf("%s\n", s[i]+1);
		
	return 0;
}