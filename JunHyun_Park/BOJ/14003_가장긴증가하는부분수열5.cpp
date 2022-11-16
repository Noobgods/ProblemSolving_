#include <cstdio>    // 14003_가장긴증가하는부분수열5 [DP], [LIS]
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> element;

int main(){
   vector<element> arr;
   vector<long long> lis, rarr;

   int N, A, R=0;   
   scanf("%lld", &N);

   lis.push_back(-1000000001);

   for(int i=0;i<N; i++){
      long long n, m;
      scanf("%lld", &n);

      if(lis.back() < n){
         lis.push_back(n);
         m = ++R;
      }
      else{
         auto k = lower_bound(lis.begin(), lis.end(), n);
         *k = n;
         m = k - lis.begin();
      }
      element input = make_pair(n, m);
      arr.push_back(input);
   }

   int n = R;
   for(vector<element>::reverse_iterator i = arr.rbegin(); i!= arr.rend(); i++){
      if(i->second == n){
         rarr.push_back(i->first);
         n--;
      }
   }


   printf("%d\n", R);
   for(vector<long long>::reverse_iterator i = rarr.rbegin(); i!= rarr.rend(); i++){
      printf("%lld ", *i);
   }

   return 0;
}