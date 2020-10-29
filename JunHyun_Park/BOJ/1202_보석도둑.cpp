#include<cstdio>    // 1202_보석도둑 [그리디] [정렬] [자료구조]
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

#define pii pair<long long, long long>

struct cmp{  
    bool operator()(const pii& a, const pii& b){
        if(a.second == b.second) return a.first>b.first;
        return a.second < b.second;
    }   
};

int main(){
    int N, K;
    scanf("%d %d", &N, &K);

    priority_queue<pii, vector<pii>, cmp> jwls;
    for(int i=0;i<N; i++){
        long long M, V;
        scanf("%lld %lld", &M, &V);
        jwls.push(make_pair(M, V));
    }

    multiset<long long> bag;
    for(int i=0;i<K; i++){
        long long C;
        scanf("%lld", &C);
        bag.insert(C);
    }

    long long answer=0;
    multiset<long long>::iterator it;
    for(int i=0; i<N && !bag.empty(); i++){
        pii jewel = jwls.top();
        jwls.pop();
        it = bag.lower_bound(jewel.first);  
        if(it != bag.end()) {
            answer+= jewel.second;
            bag.erase(it);
        }
    }

    printf("%lld", answer);
    return 0;
}