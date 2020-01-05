#include<cstdio>    // 1021_회전하는큐 [큐],[시뮬레이션]
int N, M, s, front, key;
int main(){
    int que[51];

    scanf("%d %d ", &N, &M);
    for(int i=0; i<N; i++)
        que[i] = i+1;
    while(M--){
        scanf("%d", &key);

        int i, l_shift=0, r_shift =0;
        for(i=front; que[i] != key; i= (i+1)%N )
            if(que[i] != -1)
                r_shift++;
        
        for(i=front; que[i] != key; i<=0?i=N-1:i--)
            if(que[i] != -1)
                l_shift++;   
        
        que[i] = -1;
        for(; M>0 && que[i]==-1; i= (i+1)%N){}
        front = i;
            
        s += l_shift < r_shift ? l_shift : r_shift;
    }
    printf("%d", s);
    return 0;
}