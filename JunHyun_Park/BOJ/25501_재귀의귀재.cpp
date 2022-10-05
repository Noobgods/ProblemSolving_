#include<cstdio>    // 25501_¿Á±Õ¿«±Õ¿Á [¿Á±Õ]
#include<cstring>
int N, rst;

int recursion(const char *s, int l, int r){
    rst++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    scanf("%d", &N);

    char s[1001];
    for(int i=0; i<N; i++){
        scanf("\n%s", s);
        rst = 0;
        int palindrome = isPalindrome(s);
        
        printf("%d %d\n", palindrome, rst);
    }

    return 0;
}