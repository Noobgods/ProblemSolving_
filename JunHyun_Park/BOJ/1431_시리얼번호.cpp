#include<cstdio>	// 1431_시리얼번호 [정렬],[파싱]
#include<cstring>
#include<algorithm>
#define MAXSIZE 1001
using namespace std;

struct str{
	int len;
	char s[51];
};
int N;
str S[MAXSIZE];

int sum(char *s){
	int rst = 0;
	for(int i=0; s[i]!='\0'; i++){
		if(s[i] > '0' && s[i] <= '9')
			rst += s[i] - '0';
	}
	return rst;
}
bool compare(str x, str y){
	// #1
	if(x.len != y.len)
		return x.len < y.len;

	int xsum = sum(x.s);
	int ysum = sum(y.s);
	// #2
	if (xsum != ysum)
		return xsum < ysum;
	// #3
	else {
		int i=0;
		while(x.s[i] == y.s[i] && i<x.len) i++;
		return x.s[i] < y.s[i];
	}
}

// 아니 왜 안되는 건데요..? 
/* 퀵 소트
void swap(int x, int y){
	str tc; 
	tc = S[x];
	S[x] = S[y];
	S[y] = tc;
}
void qsort(int first, int last, bool (*compare)(str,str)){
	int i = first, j= last, mid= (first+last)/2;
	while(i<=j){
		while(compare(S[i], S[mid])) i++;
		while(compare(S[mid], S[j])) j--;
		if(i<=j)
			swap(i++, j--);
	}
	if(first < j) qsort(first, j, compare);
	if(i < last) qsort(i, last, compare);
}
*/
/* 머지 소트
void merge(int left, int mid, int right, bool (*compare)(str,str)){
	int i= left, j=mid+1, k= left;
	str sorted[MAXSIZE];
	while(i<=mid && j<= right){
		if(compare(S[i], S[j]))
			sorted[k++] = S[i++];
		else
			sorted[k++] = S[j++];
	}
	
	if(i>mid)
		for(int l=j; l<=right;)
			sorted[k++] = S[l++];

	else
		for(int l=i; l<=mid;)
			sorted[k++] = S[l++];


	for(int l=left; l<=right;)
		sorted[k++] = S[l++];
	
}
void msort(int left, int right, bool (*compare)(str, str)){
	if(left<right){
		int mid = (left + right)/2;
		msort(left, mid, compare);
		msort(mid+1, right, compare);
		merge(left, mid, right, compare);
	}
}
*/
int main(){
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%s", S[i].s);
		S[i].len = strlen(S[i].s); 
	}
	sort(S, S+N-1, compare);
	for(int i=0; i<N; i++){
		printf("%s\n", &S[i].s);
	}
	return 0;
}
