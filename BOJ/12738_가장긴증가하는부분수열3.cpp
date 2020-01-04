#include<cstdio>    // 12738_가장긴증가하는부분수열3 [DP], [LIS]
#include<vector>
using namespace std;
#define max(x,y) x>y?x:y
#define INF 1000000001
vector<int> v;
int N, input, M, idx;
int main(){
	scanf("%d",&N);
    v.push_back(-INF);
	for(int i=0; i<N; i++){
        scanf("%d",&input);
        if(v.back() < input){
            v.push_back(input);
            M++;
        }
        else{
            auto vt = lower_bound(v.begin(), v.end(), input);
            *vt = input;
        }
    }
    printf("%d", M);
	return 0;
}