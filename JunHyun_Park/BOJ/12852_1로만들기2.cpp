#include <cstdio>   // 12852_1로만들기2 [DP]
#include <queue>
using namespace std;

int n;
struct one{
   int route;
   int rank;
};
one* r;

bool min(int x, int y) { 
   if (x == 0) return true;
   
   return x > y ? true : false; 
}

int main() {
	scanf("%d", &n);

	r = new one[n+1]();

   queue<int> q;
   int rank = 1;
   q.push(1);
   while(!q.empty()){
      int i = q.front();
      q.pop();

      if(i == n) break;
      if(i*3 <= n && min(r[i*3].rank, r[i].rank+1)){
         q.push(i*3);
         r[i*3].rank = r[i].rank + 1;
         r[i*3].route = i;
      }
      if(i*2 <= n && min(r[i*2].rank, r[i].rank+1)){
         q.push(i*2);
         r[i*2].rank = r[i].rank + 1;
         r[i*2].route = i;
      }
      if(i+1 <= n && min(r[i+1].rank, r[i].rank+1)){
         q.push(i+1);
         r[i+1].rank = r[i].rank + 1;
         r[i+1].route = i;
      }
   }

	printf("%d\n", r[n].rank);
   printf("%d", n);
   for(int i = r[n].route; i>=1; i = r[i].route){
      printf(" %d", i);
   }

	return 0;
}