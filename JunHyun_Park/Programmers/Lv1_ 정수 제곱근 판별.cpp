#include <string>   // Lv1_ 정수 제곱근 판별 [수학]
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double k = sqrt(n);
    double d = floor(k);

    if (k != d) { return -1; }
    else answer = (long long)pow(d+1,2);
    return answer;
}