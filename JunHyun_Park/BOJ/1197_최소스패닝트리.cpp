#include <cstdio> // 1197_최소스패닝트리 [최소신장트리]
#include <algorithm>
using namespace std;

struct node{
   int rank;
   int root;
};

struct link{
   int a;
   int b;
   int c;
};

bool cmp(const link &x, const link &y){
   return x.c < y.c ? 1 : 0;
}

int findRoot(node n[], int k){
   if(n[k].root == k) return k;
   else return n[k].root = findRoot(n, n[k].root);
}

void merge(node n[], int x, int y){
   x = findRoot(n, x);
   y = findRoot(n, y);

   if (x==y) return;

   if(n[x].rank < n[y].rank){
      n[x].root = y;
   }
   else{
      n[y].root = x;
      if(n[x].rank == n[y].rank){
         n[x].rank++;
      }
   }
}

int main(){
   int V, E, R = 0;
   node *n;
   link *k;
   
   scanf("%d %d", &V, &E);

   n = new node[V+1]();
   k = new link[E]();

   for(int i=1; i<=V; i++){
      n[i].root = i;
      n[i].rank = 0;
   }
   
   for(int i=0; i<E; i++){
      int A, B, C;
      scanf("%d %d %d", &A, &B, &C);

      k[i].a = A;
      k[i].b = B;
      k[i].c = C;
   }

   sort(k, k+E, cmp);

   for(int i=0; i<E; i++){
      if(findRoot(n, k[i].a) != findRoot(n, k[i].b)){
         merge(n, k[i].a, k[i].b);
         R += k[i].c;
      }
   }
   
   printf("%d", R);

   delete[] n;
   delete[] k;
   return 0;
}