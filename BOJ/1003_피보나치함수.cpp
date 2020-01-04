#include <cstdio>   // 1003_피보나치함수 [DP]
int n, z, fib[41] = { 0, 1 };
int fibonacci(int n) {
	if (fib[n] > 0)
		return fib[n];
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else 
		return fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
	scanf("%d", &n);
	while (n) {
		scanf("%d", &z);
		fib[z] = fibonacci(z);

		if(z==0) printf("1 0\n");
		else if (z == 1) printf("0 1\n");
		else printf("%d %d\n", fib[z-1], fib[z]);
		n--;
	}
	return 0;
}