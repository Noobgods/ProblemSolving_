#include<cstdio>    // 2607_비슷한단어 [문자열비교]
#include<cstring>
char S[101][11],N, R;
int C[26], t[26];
int main(){
    scanf("%d\n",&N);

    scanf("%s", S[0]);

    for(int i=0; S[0][i] != '\0'; i++)
        C[S[0][i]- 'A']++;

    for(int i=1; i<N;i++){
        scanf("%s", S[i]);
        bool r = true;
        int sameCheck = 2;
        for(int j=0; S[i][j] != '\0'; j++) t[S[i][j]- 'A'] ++;
        int d =strlen(S[0]) - strlen(S[i]);
        if(d > 1 || d < -1)
            r = false;
        else for(int j=0; j<26; j++){
            if(C[j] - t[j] > 1 || C[j] - t[j] < -1){
                r = false;
                break;
            }
            if(C[j] - t[j] != 0){
                if(sameCheck)
                    sameCheck--;
                else{
                    r = false;
                    break;
                }
            }
        }
        for(int j=0; j<26; j++) t[j] =0;
        if(r) R++;
    }
    printf("%d\n", R);
	return 0;
}