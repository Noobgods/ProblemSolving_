#include<cstdio>    // 1158_조세퍼스문제 [링크드리스트], [큐]
int N, M, queue[5001];
int main(){
    scanf("%d %d", &N, &M);
    
    for(int i=1; i<=N; i++)
        queue[i-1] = i;
    
    int i, q = 1;
    printf("<");
    for(int size = N;size > 0;){
        i = 0;
        for(int j=0, b_s = size; j < b_s; j++){
            if(q == M){
                printf("%d", queue[j]);
                q = 1;
                size--;
                if(size <= 0) break;
                else printf(", ");
            } 
            else {
                queue[i++ % b_s] = queue[j];
                q++;
            }
        }
    }
    printf(">");
    return 0;    
}