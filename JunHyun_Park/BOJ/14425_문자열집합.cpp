#include <cstdio>       // 14425_문자열집합 [해시테이블]
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    int N, M, R = 0;
    unordered_set<string> hash;

    scanf("%d %d", &N, &M);

    string str;
    char cstr[501];
    for(int i=0; i<N; i++){
        scanf("%s", cstr);
        str = cstr;

        hash.insert(str);
    }

    for(int i=0; i<M; i++){
        scanf("%s", cstr);
        str = cstr;
        if(hash.find(str) != hash.end()) {
            R++;
        }
    }

    printf("%d\n", R);
    return 0;
}