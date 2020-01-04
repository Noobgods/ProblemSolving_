#include <cstdio>   // 2751_수정렬하기2 [정렬]
int n, arr[1000000];

void swap(int x, int y);
void quickSort(int left, int right);

int main(){
	scanf("%d",&n);

	for(int i=0; i<n; ++i)
		scanf("%d", &arr[i]);
	
	quickSort(0, n-1);

	for(int i=0; i<n; ++i)
		printf("%d ",arr[i]);

	return 0;
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void quickSort(int left, int right){
	int i = left, j = right;
	int pivot = arr[(left + right)/2];
	
	while(i<=j){
		while(arr[i] < pivot) i++;
		while(arr[j] > pivot) j--;
		if(i<=j) swap(&arr[i++], &arr[j--]);
	}
	if(left < j) quickSort(left, j);
	if(i < right) quickSort(i, right);
}