#include<cstdio>    // 1717_집합의표현 [Union-Find]
int N, M, A[1000001], B[1000001];
int find(int t){
   if(A[t] != t) return A[t] = find(A[t]);
   else return t; 
}
void merge(int x, int y ){
    x = find(x);
    y = find(y);

    if(x == y)
         return;

    if(B[x] < B[y]){
        A[x] = y;
    } else{
        A[y] = x;
        
        if(B[x] == B[y])
            B[x]++;
    }
}
int main(){
    scanf("%d %d",&N,&M);    
        
    for(int i=1;i<=N;i++){
        A[i] = i;
        B[i] = 0;
    }
        
    for(int i=0;i<M;i++){
        int o, x, y;
        scanf("%d %d %d", &o,&x,&y);
        
        if(o){
            if(find(x) == find(y))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else    merge(x,y);
    }
    return 0;
}