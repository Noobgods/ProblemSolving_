#include<cstdio>
using namespace std;
#define max(x,y) x>y?x:y
int A[100000],N;
long long int R;
long long int leftsplit(int n, int s){
    if(n < 0 || s > A[n]) return 0;
    else return leftsplit(n-1, s)+ s;
}
long long int rightsplit(int n, int s){
    if(n >= N || s > A[n]) return 0;
    else return rightsplit(n+1, s)+ s;
}
long long int split(int n){
    return leftsplit(n-1, A[n]) + rightsplit(n+1, A[n]) + A[n];
}
int main(){
    for(;;){
        scanf("%d", &N);
        int i;
        for(i=0; i<N; i++)
            scanf("%d",&A[i]);
        
        if(i==0) break;

        R = 0;
        for(i=0; i<N; i++)
            R = max(R, split(i));
        
        printf("%d\n",R);
    }
}