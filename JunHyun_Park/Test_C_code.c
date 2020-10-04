#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct point {
   int L, H;
}point;

vector<point> pL;
vector<point> pR;
vector<point> pC;
int s2;

bool test(point &a, point &b) {
   if (a.H >= b.H) {
      return false;
   }
   else {
      return true;
   }
}

bool test2(point &a, point &b) {
   if (a.L > b.L) {
      return false;
   }
   else {
      return true;
   }
}

void function(vector<point> v, int start, int end, char dir) {
   if (end == 0 || start == (v.size() - 1)) {
      return;
   }
   int max = INT_MIN;
   point temp;
   int index = 0;
   for (int i = start; i < end; i++) {
      if (v[i].H >= max) {
         max = v[i].H;
         temp.H = v[i].H;
         temp.L = v[i].L;
         index = i;
      }
   }
   if (dir == 'L') {
      pL.push_back(temp);
      function(v, 0, index, 'L');
   }
   if (dir == 'R') {
      if (index == 0) {
         return;
      }
      pR.push_back(temp);
      function(v, index , v.size(), 'R');
   }
   return;
}

int main() {
   int n;
   vector<point> v;
   cin >> n;
   for (int i = 0; i < n; i++) {
      int L, H;
      cin >> L >> H;
      v.push_back({ L,H });
   }
   sort(v.begin(), v.end(), test);
   int max;
   vector<int> index;
   max = v.back().H;
   sort(v.begin(), v.end(), test2);
   for (int i = 0; i < n; i++) {
      if (v[i].H == max) {
         index.push_back(i);
         pC.push_back(v[i]);
      }
   }
   function(v, 0, index.front(), 'L');
   function(v, index.back() + 1, v.size(), 'R');
   sort(pL.begin(), pL.end(), test2);
   sort(pC.begin(), pC.end(), test2);
   int answer = 0;
   for (int i = 0; i < pC.size(); i++) {
      answer += max;
   }
   pL.push_back({ pC.front().L,pC.front().H });
   pR.push_back({ pC.back().L,pC.back().H });
   sort(pR.begin(), pR.end(), test2);
   for (int i = 0; i < pL.size() - 1; i++) {
      answer += (pL[i + 1].L - pL[i].L)*pL[i].H;
   }
   for (int i = pR.size() - 1; i > 0; i--) {
      answer += (pR[i].L - pR[i - 1].L)*pR[i].H;
   }
   cout << answer << endl;
}