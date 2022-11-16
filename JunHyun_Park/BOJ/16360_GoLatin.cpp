#include<cstdio>	// 16360_GoLatin [문자열처리]
#include<cstring>
char la[11][5]={"as", "ios", "ios", "les", "anes", "os", "res", "tas", "us", "ves", "was"};
char en[11]={'a', 'i', 'y', 'l', 'n', 'o', 'r', 't', 'u', 'v', 'w'};
int main(){
	int T;
	char s[50];
	for(scanf("%d",&T); T--;){
		scanf("%s", s);
		char *r = &s[strlen(s)-2];
		
		for(int i=0; i<11; i++){
			if(strcmp(r, "ne") == 0){
				r[0] = '\0';
				strcat(s,"anes");
				break;
			}
			else if(r[1] == en[i]) {
				r[1] = '\0';
				strcat(s,la[i]);
				break;
			}
			else if(i==10){
				strcat(s,"us");
				break;
			}
		}
		printf("%s\n",s);
	}
	return 0;
}