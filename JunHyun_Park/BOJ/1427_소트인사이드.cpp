#include<iostream>  // 1426_소트인사이드 [정렬]
using namespace std;

int num[10], n;
int main(){
    char c = 32;
    while(1){
        c = getchar();
        if(c == 10) break;
        else {
            num[c-'0']++;
            n++;
        }
    }

    for(int i=9; i>=0; i--)
        if(num[i] > 0)
            for(int j=0; j<num[i]; j++)
                printf("%d", i);
    
    return 0;
}