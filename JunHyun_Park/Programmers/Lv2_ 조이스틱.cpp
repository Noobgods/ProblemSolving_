#include <string>   // Level2_ 조이스틱 [그리디]
#include <vector>
#include <string.h>

#include <iostream>
#define calc(c) c - 'A' < 'Z' - c + 1 ? c - 'A' : 'Z' - c +1
using namespace std;

int right(int n, int start, string name, string target){
    int r = 0;
    if(name == target) {
        return 0;
    }
    if(n == target.length()) {
        n = 0;
    }

    name[n] = target[n];
    r += calc(target[n]); 
    r += right(n+1, start, name, target) + 1;
    return r;
}

int left(int n, int start, string name, string target){
    int r = 0;
    if(name == target) {
        return 0;
    }
    if(n < 0) {
        n = target.length()-1;
    };

    name[n] = target[n];
    r += calc(target[n]);
    r += left(n-1, start, name, target) +1;
    return r;
}

int solution(string name) {
    int answer = 10000000;

    for(int i=0; i<name.length(); i++){
        char s[21] = "AAAAAAAAAAAAAAAAAAAA";
        s[name.length()] = '\0';

        int n = calc(name[i]);
        s[i] = name[i];
        n += left(i-1, i, s, name) < right(i+1, i, s, name) ? left(i-1, i, s, name) : right(i+1, i, s, name);
        n += i;
        if (answer > n) answer = n;
    }

    return answer;
}