#include <cstdio>   //1062_가르침 [백트래킹]
#define MAX(x,y) x>y?x:y

unsigned int word[50], max, N, K, check;

int GetCnt(){
    int cnt = 0;
    for(int i=0; i<N; i++)
        if ((check | word[i]) == check)
            cnt++;

    return cnt;
}

void BT(int x, int cnt){
    if(cnt == K)
        max = MAX(max, GetCnt());
    else for(int i=x; i<26; i++){
        if (!(check & 1 << i)) {
            check |= 1 << i;
            BT(i, cnt+1);
            check &= ~(1 << i);
        }
    }
}

int main(){
    scanf("%d %d ",&N, &K);
    
    for(int i=0;i<N;i++){
        while(1){
            char c;
            c = getchar();
            if(c == '\n') break;
            word[i] |=  1 << c-'a';
        }
    }
    
    if (K < 5) { printf("0"); return 0;}

    check |= 1<<0 | 1<<2 | 1<<8 | 1<<13 | 1<<19;
    BT(0, 5);

    printf("%d\n", max);

    return 0;
}