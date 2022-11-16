#include<cstdio>    // 1717_집합의표현 [Union-Find]
int N, M, root[1000001], rank[1000001];
int find(int t){
   if(root[t] == t) return t; 
   else return root[t] = find(root[t]);
}
void merge(int x, int y ){
    x = find(x);
    y = find(y);

    if(x == y)
         return;

    //
    if(rank[x] < rank[y]){
        root[x] = y;
    } 
    else{
        root[y] = x;
        
        if(rank[x] == rank[y])
            rank[x]++;
    }
}

int main(){
    scanf("%d %d",&N,&M);    
        
    for(int i=1;i<=N;i++){
        root[i] = i;
        rank[i] = 0;
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