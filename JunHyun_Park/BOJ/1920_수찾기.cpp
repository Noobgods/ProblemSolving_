#include <cstdio>   // 1920_수찾기 [이분탐색]
int n, A[100000], m, mt;

void sort(int l, int r);
bool search(int l, int r, int key);
int main(){
	scanf("%d", &n);

	for(int i=0; i<n; ++i)
		scanf("%d", &A[i]);

	sort(0, n-1);
	scanf("%d", &m);

	for(int i=0; i<m; ++i){
		scanf("%d", &mt);

		if(search(0, n-1, mt))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
void swap(int *x, int *y){int temp = *x;*x = *y;*y = temp;}
void sort(int l, int r){
	int i=l, j=r, pivot = A[(l+r)/2];
	
	while(i<=j){
		while(A[i] < pivot) i++;
		while(A[j] > pivot) j--;
		if(i<=j) swap(&A[i++], &A[j--]);
	}
	if(l<j) sort(l, j);
	if(i<r) sort(i, r);
}

bool search(int l, int r, int key){
	if(l > r) return false;
	int pivot = (l+r)/2;
	if(A[pivot] == key)
		return true;
	else if(A[pivot] < key)
		return search(pivot + 1, r, key);
	else
		return search(l, pivot - 1, key);
}