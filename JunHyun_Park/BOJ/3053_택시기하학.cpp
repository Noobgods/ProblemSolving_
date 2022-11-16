#include<cstdio>    // 3053_택시기하학 [수학], [기하 알고리즘], [구현]
#include<math.h>
#define PI 3.141592653589793

double R;
int main(){
    scanf("%lf",&R);

    printf("%lf\n%lf", PI*pow(R,2),2*abs(R)*abs(R));
	return 0;
}