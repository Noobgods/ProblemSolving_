#include <cstdio>	// 1019 책 페이지
#define ll  long long
 
ll start, finish, temp;
int answer[10];
 
void sol(int n) {
    for (int j = n; j > 0; j/=10) {
        answer[j%10] += temp;
    }
}
 
int main(int argc, char const *argv[]) {
    start = 1;
    temp = 1;
    scanf("%d",&finish);
    
    while (start <= finish) {
        while (start % 10 != 0 && start <= finish) {
            sol(start);
            start++;
        }
    
        if (start > finish) {
            break;
        }
    
        while (finish % 10 != 9 && start <= finish) {
            sol(finish);
            finish--;
        }
    
        ll cnt = (finish/10) - (start/10) + 1;
        for (int i = 0; i < 10; i++) {
            answer[i] += cnt * temp;
        }
    
        start /= 10;
        finish /= 10;
        temp *= 10LL;
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d ",answer[i]);
    }
    return 0;
}