#include <string>   // 3663_고득점 [그리디], [브루트포스]
#include <vector>
#include <string.h>

#include <iostream>
using namespace std;

int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) {
    int answer = 0, j, k = 2e9;
    for(auto ch : name){
        answer += LUT[ch - 'A'];
    }
    
    int len = name.length();
    for(int i=0; i<len; i++){
        for(j = i+1; j<len && name[j] == 'A'; j++);
        if(name[i]=='A'&& j == len+1) break;
        int right = i*2 + len - j;
        int left = i + (len - j)*2;
        int t = left < right ? left : right;
        k = t < k ? t : k;
    }

    return answer + k;
}

int main(){
    string name;
    int n;
    cin >> n;
    while(n--){
        cin >> name;

        cout << solution(name)<<endl;
    }
}