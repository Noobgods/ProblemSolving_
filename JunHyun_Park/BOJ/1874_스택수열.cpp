#include <cstdio>   // 1874_스택수열 [스택]
int N, stack[100001], seq[100001];
char str[200001];
int main(){
    int i, j, s, top=0;
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d", &seq[i]);
    
    for(i=1,j=0,s=0; j<N;){
        if(stack[top] == seq[j]){
            str[s++] = '-';
            j++;
            top--;
        }
        else if(i>N){
            str[0] = -1;
            break;
        }
        else {
            str[s++] = '+';
            stack[++top] = i++;
        }
    }
    for(i=0; i<2*N; i++){
        if(str[0]==-1) {
            printf("NO\n");
            break;
        }
        else
            printf("%c\n",str[i]);
    }
    return 0;    
}