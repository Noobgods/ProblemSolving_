#include <cstdio>   // 1015_수열정렬 [정렬]

int main() {
	int n;
	int A[50];
	int P[50] = { 0, };

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		for (int j = 0; j<i; j++) {
			if (A[j] > A[i])
				P[j]++;
			else if (A[j] <= A[i])
				P[i]++;
		}
	}
	for (int i = 0; i<n; i++)
		printf("%d ", P[i]);
	return 0;
}