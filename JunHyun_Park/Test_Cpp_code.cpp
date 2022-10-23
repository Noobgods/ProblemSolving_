#include <cstdio>
#include <algorithm>
using namespace std;

struct coordinate{
   int x;
   int y;
   int z;
};

struct planet{
   planet* root;
   coord coord;
   int rank;
};

struct link{
   int* x;
   int* y;
   int z;
};

int N, R = 0;
   
planet *p;
link *k;
int *cd, **cs;

void cSort(int first, int last){
   int i = first, j = last;
   int mid = *cs[(first + last)/2];

   while(i<=j){
      while(*cs[i] < mid) i++;
      while(*cs[j] > mid) j--;
      if(i<=j){
         int *t = cs[i];
         cs[i] = cs[j];
         cs[j] = t;
         i++, j--;
      }
   }

   if(first < j) cSort(first, j);
   if(i < last) cSort(i, last);
}

planet* findRoot(int* k){
   if(k->root == k) return k;
   else return findRoot(k->root);
}

void merge(planet* x, planet* y){
   planet* c1 = findRoot(x);
   planet* c2 = findRoot(y);

   if (c1==c2) return;

   if(x->rank < y->rank){
      x->root = c2;
   }
   else{
      y->root = c1;
      if(x->rank == y->rank){
         x->rank++;
      }
   }
}

int main(){
   scanf("%d", &N);

   p = new planet[N]();
   k = new link[(N-1)*3]();
   cd = new int[N*3]();
   cs = new int*[N*3]();

   for(int i=0; i<N; i++){
      scanf("%d %d %d", &cd[i], &cd[N+i], &cd[N+N+i]);
      cs[i] = cd+i; cs[N+i] = cd+N+i; cs[N+N+i] = cd+N+N+i;
      p[i].root = &p[i];
      p[i].rank = 0;
   }

   cSort(0, N-1);
   cSort(N, N*2-1);
   cSort(N*2, N*3-1);
   
   for(int i=0; i<N-1; i++){
      if (i%N == 0 && i != 0) continue;
      k[i].x = cs[i];
      k[i].y = cs[i+1];
      k[i].z = *cs[i+1] - *cs[i];
   }
   
   sort(k, k+((N-1)*3), [](const link& a, const link& b){return a.z < b.z ? true:false;});
   for(int i=0; i<(N-1)*3; i++){
      printf("%d ", k[i].z);
   }

   // for(int i=0; i<E; i++){
   //    if(findRoot(n, k[i].a) != findRoot(n, k[i].b)){
   //       merge(n, k[i].a, k[i].b);
   //       R += k[i].c;
   //    }
   // }
   
   printf("%d", R);

   delete[] p;
   delete[] k;
   delete[] cd;
   delete[] cs;
   return 0;
}