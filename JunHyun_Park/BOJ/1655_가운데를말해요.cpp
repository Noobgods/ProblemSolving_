#include <cstdio>    // 1655_가운데를말해요 [우선순위큐]
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq_g;
    priority_queue<int, vector<int>, less<int>> pq_l;

    int N, in;

    scanf("%d", &N);

    while(N--){
        scanf("%d", &in);

        if(pq_l.empty()) pq_l.push(in);
        else {
            if(in <= pq_l.top()){
                pq_l.push(in);
                if(pq_l.size() > pq_g.size()+1){
                    pq_g.push(pq_l.top());
                    pq_l.pop();
                }
            }
            else{
                pq_g.push(in);
                if(pq_g.size() > pq_l.size()){
                    pq_l.push(pq_g.top());
                    pq_g.pop();
                }
            }
        }
        printf("%d\n", pq_l.top());
    }

    return 0;
}
