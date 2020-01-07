#include<cstdio>
#include<string>
#include<vector>
using namespace std;

char C[60],N;
int n_o;
vector<bool> O;
vector<int> A;
int main(){
    scanf("%s",C);    
    int i=0, k=-1;

    do{
        if(C[i] < '0' && k != -1) {
            char n[10] = {0,};
            for(int j=0; j<i-k; j++)
                n[j] = C[k+j];
            A.push_back(atoi(n));
            k = -1;
            if(C[i] == '+'){O.push_back(true);}
            if(C[i] == '-'){O.push_back(false);}
        }
        else if(k == -1){
            k = i;
        }
    }while(C[i++] != '\0' || k !=-1);
    
    vector<int>::iterator iter = A.begin();
    vector<bool>::iterator O_iter = O.begin();
    k = 0;
    for(int i=0;O[i]!=O.size();){
        if(O[i]){
            A[i] += A[i+1];
            iter += i+1;
            O_iter += i;
            k++;
            A.erase(iter);
            O.erase(O_iter);
            printf("%d %d\n" ,A[i], i);
        }
        else i++;
    }

    int R = 2*A[0];
    for(auto v : A){
        R -= v;
        printf("%d ",v);
    }

    printf("%d", R);
    return 0;
}