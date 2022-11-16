#include<iostream> // 10816_숫자카드 [이분탐색]
#include<cstdio>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a; 

int lb(int l, int r, int k){
    while(l < r){
        int m = (l+r)/2;
        if(a[m] >= k) r = m;
        else l = m +1;
    }
    return r;
}
int ub(int l, int r, int k){
    while(l < r){
        int m = (l+r)/2;
        if(a[m] > k) r = m;
        else l = m +1;
    }
    return r;
}
int n, m;
int main(){

    scanf("%d", &n);
    for(int i=0;i<n; i++){
        int input;
        scanf("%d", &input);
        a.push_back(input);
    }

    sort(a.begin(), a.end());

    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int input;
        scanf("%d", &input);
        
        printf("%d ", ub(0, n, input)- lb(0, n, input));
    }
}