#include<iostream>  // 1475_방번호 [수학], [문자열처리]
using namespace std;
int N[9], s;
int main(){
    char c = -1;
    while(1){
        c = getchar();
        if(c == 10) break;
        if(c == '9') c-=3;
        N[c-'0']++;
    }
    N[6] = (N[6] +1)/2;
    for(int i=0; i<9; i++){
        if(N[i] > s)
            s = N[i];
    }
    printf("%d", s);
    return 0;    
}