#include<cstdio> 	// 2671_잠수함식별 [정규식]
bool S[201], R;
int N, idx;
bool check1(int x){
	// 1
	int t = x++;
	if(x >= N) return false;// 끝

	// 10
	if(!S[x++]);
	else return false;
		
	t = x;
	if(x >= N) return false;// 끝

	// 100~
	while(!S[x]){x++;}
	if(x == t) return false;

	t = x;
	if(x >= N) return false;// 끝
	
	// 100~1~
	while(S[x]){x++;}
	if(x == t) return false;
	else idx = x;
	return true;
}
bool check2(int x){
	int t = x++;
	if(S[x++]) {
		idx = x;
		return true;
	}
	else return false;
}
int main(){
	for(int i=0;; i++){
		char c=getchar();
		if(c == '\n'){
			N = i; break;
		}
		if(c=='1') S[i] = true;
		if(c=='0') S[i] = false;
	}
	
	R = true;
	while(idx<N){
		if(S[idx]){
			if(check1(idx));
			else {
				R = false;
				break;
			}
		}
		else if(S[idx-2] && check1(idx-1));
		else {
			if(check2(idx));
			else {
				R = false;
				break;
			}
		}
	}
	if(R) printf("SUBMARINE");
	else printf("NOISE");

	return 0;
}