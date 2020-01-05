#include<cstdio>    // 10453_문자열변환 [큐]
#include<cstring>
#include<queue>
using namespace std;
int N, T; 
char A[100001], B[100001];
queue<int> q1, q2;
int main(){
    for(scanf("%d",&T);T--;N=0){
        scanf("%s %s", A, B);
        int l = strlen(A), idx = -1;
        for(int i=0; i<l; i++){
            if(A[i] != B[i]){
                if(A[i] == 'b'){
                    q1.push(i);
                    if(!q2.empty()){
                        N += q1.front() - q2.front();
                        q1.pop();
                        q2.pop();
                    }
                }
                if(A[i] == 'a') {
                    q2.push(i);
                    if(!q1.empty()){
                        N += q2.front() - q1.front();
                        q1.pop();
                        q2.pop();
                    }
                }
            }
        }
        printf("%d\n",N);
    }
    return 0;
}