#include <stdio.h>
 
long long int two[3];
long long int five[3];
 
long long int mymin(long long int first, long long int second)
{
    if (first < second)    return first;
    return second;
}
 
void process(long long int number, int flag)
{
    long long int i;
    long long int t = 0, f = 0;
 
    for (i = 2; i <= number; i *= 2)
        t += number / i;
 
    for (i = 5; i <= number; i *= 5)
        f += number / i;
 
    two[flag] = t;
    five[flag] = f;
}
 
int main()
{
    long long int n, m;
 
    scanf("%lld %lld", &n, &m);
 
    process(n, 0);
    process(m, 1);
    process(n - m, 2);
 
    printf("%lld\n", mymin(two[0] - two[1] - two[2], five[0] - five[1] - five[2]));
 
    return 0;
}