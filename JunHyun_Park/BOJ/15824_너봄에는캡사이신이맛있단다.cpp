#include <iostream>     // 15824_너봄에는캡사이신이맛있단다 [조합], [수학]
#include <vector>   
#include <algorithm>
using namespace std;

typedef long long ll;

#define MOD 1000000007

int N;
vector<int> v, pow;
ll r;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    
    pow.push_back(1);
    for(int i=1; i<=N; i++){
        pow.push_back((2*pow[i-1])%MOD);
    }
    for(int i=0; i<N; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<N; i++){
        ll x = pow[i];
        ll n = pow[N - i - 1];
        r += (v[i]%MOD) * x%MOD;
        r -= (v[i]%MOD) * n%MOD;
        r = ((r%MOD)+MOD)%MOD;
    }
    cout << r;
    return 0;
}