#include<cstdio>	// 2108_통계학 [정렬], [구현]
int N, num[8001], count, s;
double sum;
int main(){
    short ins, mid, t, min, max;
    max=mid=-4001;
    min=4001;

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &ins);
        num[4000+ins]++;
        sum += ins;
        if(ins<min) min=ins;
        if(ins>max) max=ins;
    }
    count = N;
    for(int i=min+4000; i<=max+4000; i++){
        if(num[i]>s) {
            s = num[i];
            t = 1;
            ins = i-4000;
        }
        else if(num[i]==s && t) {
            ins = i-4000;
            t = 0;
        }
        count -= num[i];
        if(count <= N/2 && mid == -4001)
            mid = i-4000;
    }
    float avg;
    if(sum/N <0) avg = (float)(sum/N)- 0.5; else avg = (float)(sum/N) + 0.5;
    printf("%d\n%d\n%d\n%d",(int)avg,mid,ins,max-min);
    return 0;
}