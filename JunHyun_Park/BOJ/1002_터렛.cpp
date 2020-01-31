#include<cstdio>    // 1002_터렛 [수학]
#include<math.h>

int R,T, Ax, Ay, Ar, Bx, By, Br;
int main(){
    scanf("%d", &T);
    
    while(T--){
        scanf("%d %d %d %d %d %d", &Ax, &Ay, &Ar, &Bx, &By, &Br);
        if(Ax == Bx && Ay == By && Ar == Br){
            R = -1;
        }
        else {
            double r = (double)sqrt(pow(Bx-Ax, 2) + pow(By-Ay, 2));
            double d = r-(double)(Ar+Br);
            if (d > 0.0 || (int)r+Ar < Br || (int)r+Br < Ar) R = 0;
            else if(d == 0.0 || (int)r+Ar == Br || (int)r+Br == Ar) R = 1;
            else if(d < 0.0 || (int)r+Ar > Br || (int)r+Br > Ar) R = 2;
        }
        printf("%d\n",R);
    }
	return 0;
}