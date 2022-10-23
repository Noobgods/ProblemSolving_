#include <cstdio>    // 2887_행성터널 [최소신장트리], [정렬]
#include <algorithm>
using namespace std;

struct coordinate{
   int x;
   int y;
   int z;
};

struct planet{
   planet* root;
   coordinate coord;
   int rank;
};

struct link{
   planet* x;
   planet* y;
   int z;
};

int N, R = 0;
   
planet *p;
link *k;
planet **csx, **csy, **csz;

bool cmpX(const planet &x, const planet &y){
   return x.coord.x < y.coord.x ? 1 : 0;
}
bool cmpY(const planet &x, const planet &y){
   return x.coord.y < y.coord.y ? 1 : 0;
}
bool cmpZ(const planet &x, const planet &y){
   return x.coord.z < y.coord.z ? 1 : 0;
}

void cSort(planet **cs, int first, int last, bool (*cmp)(const planet&, const planet&)){
   int i = first, j = last;
   planet *mid = &(*cs[(first + last)/2]);


   while(i<=j){
      while(cmp(*cs[i], *mid)) i++;
      while(cmp(*mid, *cs[j])) j--;
      if(i<=j){
         planet *t = cs[i];
         cs[i] = cs[j];
         cs[j] = t;
         i++, j--;
      }
   }

   if(first < j) cSort(cs, first, j, cmp);
   if(i < last) cSort(cs, i, last, cmp);
}

planet* findRoot(planet* k){
   if(k->root == k) return k;
   else return k->root = findRoot(k->root);
}

void merge(planet* x, planet* y){
   x = findRoot(x);
   y = findRoot(y);

   if (x==y) return;

   if(x->rank < y->rank){
      x->root = y;
   }
   else{
      y->root = x;
      if(x->rank == y->rank){
         x->rank++;
      }
   }
}

int main(){
   scanf("%d", &N);

   p = new planet[N]();
   k = new link[(N-1)*3]();
   csx = new planet*[N]();
   csy = new planet*[N]();
   csz = new planet*[N]();

   for(int i=0; i<N; i++){
      scanf("%d %d %d", &p[i].coord.x, &p[i].coord.y, &p[i].coord.z);
      csx[i] = csy[i] = csz[i] = &p[i]; 
      p[i].root = &p[i];
      p[i].rank = 0;
   }

   cSort(csx, 0, N-1, cmpX);
   cSort(csy, 0, N-1, cmpY);
   cSort(csz, 0, N-1, cmpZ);
   
   for(int i=0; i<N-1; i++){
      k[i].x = csx[i];
      k[i].y = csx[i+1];
      k[i].z = csx[i+1]->coord.x - csx[i]->coord.x;

      k[i+N-1].x = csy[i];
      k[i+N-1].y = csy[i+1];
      k[i+N-1].z = csy[i+1]->coord.y - csy[i]->coord.y;

      k[i+(N-1)*2].x = csz[i];
      k[i+(N-1)*2].y = csz[i+1];
      k[i+(N-1)*2].z = csz[i+1]->coord.z - csz[i]->coord.z;
   }
   
   sort(k, k+((N-1)*3), [](const link& a, const link& b){return a.z < b.z ? true:false;});

   for(int i=0; i<(N-1)*3; i++){
      if(findRoot(k[i].x) != findRoot(k[i].y)){
         merge(k[i].x, k[i].y);
         R += k[i].z;
      }
   }
   
   printf("%d", R);

   delete[] p;
   delete[] k;
   delete[] csx;
   delete[] csy;
   delete[] csz;
   return 0;
}