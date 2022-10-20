#include <cstdio>
#include <algorithm>
using namespace std;

struct coordinate{
   int x;
   int y;
   int z;
};

struct planet{
   coordinate coord;
   planet* root;
   int rank;
};

struct link{
   planet* x;
   planet* y;
   int z;
};

bool cmpX(const planet &p1, const planet &p2){
   return p1.coord.x < p2.coord.x ? 1 : 0;
}
bool cmpY(const planet &p1, const planet &p2){
   return p1.coord.y < p2.coord.y ? 1 : 0;
}
bool cmpZ(const planet &p1, const planet &p2){
   return p1.coord.z < p2.coord.z ? 1 : 0;
}

planet* findRoot(planet n[], planet* k){
   if(n[k].root == k) return k;
   else return n[k].root = findRoot(n, n[k].root);
}

void merge(planet* x, planet* y){
   coordinate* c1 = findRoot(n, x);
   coordinate* c2 = findRoot(n, y);

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
   int N, R = 0;
   planet *p;
   link *k;
   
   scanf("%d", &N);

   p = new planet[N]();
   k = new link[]();

   for(int i=0; i<N; i++){
      scanf("%d %d %d", &p[i].coord.x, &p[i].coord.y, &p[i].coord.z);
      p[i].root = &p[i];
      p[i].rank = 0;
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