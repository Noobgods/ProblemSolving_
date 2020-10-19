#include <string> // Level2_ 다리를 지나는 트럭 [큐]
#include <vector>
#include <queue>

#include <iostream>

using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int weightSum = truck_weights[0], idx=1, i;
    queue<pair<int, int>> bridge;
    bridge.push(make_pair(1, truck_weights[0]));

    for(i=2;;i++){
        if( bridge.front().first + bridge_length == i){
            weightSum -= bridge.front().second;
            bridge.pop();
        }
        if( idx == truck_weights.size() && bridge.empty()) return i;
        if( weight >= weightSum + truck_weights[idx] && idx < truck_weights.size()){
            weightSum += truck_weights[idx];
            bridge.push(make_pair(i, truck_weights[idx++]));
        }
    }
    return 0;
}