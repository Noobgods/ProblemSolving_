#include<cstdio>    // 3009_네번째점 [수학]
int x[2][2]={0,},y[2][2]={0,};
int main(){
    int A,B,kx, ky;
    for(int i=0; i<3; i++){
        scanf("%d %d",&A, &B);
        
        for(int j=0; j<2; j++){
            if (x[j][0] == A){
                x[j][1]++;
                break;
            }
            else if(x[j][0] == 0){
                x[j][0] = A;
                break;
            }
        }
        for(int j=0; j<2; j++){
            if (y[j][0] == B){
                y[j][1]++;
                break;
            }
            else if(y[j][0] == 0){
                y[j][0] = B;
                break;
            }
        }
    }
    for(int i=0; i<2; i++){
        if(x[i][1] ==0)
            kx = x[i][0];
        if(y[i][1] ==0)
            ky = y[i][0];
    }
    printf("%d %d", kx, ky);
    return 0;
}