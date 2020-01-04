#include<cstdio>    // 1026_보물 [정렬],[탐색]
#include<algorithm>
using namespace std;

int main() {
	int n,sum =0;
	int A[50], B[50];

	scanf("%d",&n);
	
	for (int i = 0; i < n; i++)
		scanf("%d",&A[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &B[i]);

	sort(A, A + n);
	sort(B, B + n);

	for (int i = 0; i < n; i++)
		sum += A[i] * B[n-i-1];

	printf("%d", sum);
	
	return 0;
}