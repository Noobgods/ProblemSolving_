#include <string>   // Level3_ 입국심사 [이분탐색]
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long l=0, r = (long long)(times[times.size()-1]) * n;
    long long answer = r;

    while(l<=r){
        long long mid= (l+r)/2;
        long long size = 0;
        for(int i = 0; i<times.size(); i++){
            size += mid / times[i];
        }
        if(size < n) l = mid+1;
        if(size >= n) {
            if(mid < answer)
                answer = mid;
            r = mid-1;

        } 
    }

    return answer;
}


// 입출력
int main(){
    int n, n_t;
    vector<int> times; 

    cin >> n >> n_t;

    for(int i=0;i<n_t; i++){
        int k;
        cin >> k;
        times.push_back(k);
    }

    cout << solution(n, times);
}