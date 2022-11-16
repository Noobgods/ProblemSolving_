#include <cstdio>
#include <string>
using namespace std;

struct node{
    bool c[256][16];
    node* parent;
};
node feed[16][15];

int main(){
    
    int N, K;
    scanf("%d", &N);

    while(N--){
        char s[16];
        scanf("%d", &K);

        for(int i=0; i<K; i++){
            scanf("%s", s);

            for(int j=0; s[j]!='\0'; j++){
                feed[i].c[s[j]][j] = true;
            }
        }
    }

    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            
        }
    }
}  