#include<cstdio>	// 2658_직각이등변삼각형찾기 [구현]
#include<cstring>

bool A[12][12],R;
int tri[3][2];
bool square_1(int x, int y){
	int i,j,len;
	bool S[30][30];
	memset(S, 0, sizeof(S));
	for(i=0; A[x][y+i]; i++);
	len = i;

	for(i=0; i<len; i++){
		for(j=0; j<len-i; j++){
			S[x+i][y+j] = true;
		}
	}

	for(i=1; i<=10; i++)
		for(j=1; j<=10; j++)
			if(A[i][j] != S[i][j]) return false;
	tri[0][0] = x;
	tri[0][1] = y;
	tri[1][0] = x;
	tri[1][1] = y+len-1;
	tri[2][0] = x+len-1;
	tri[2][1] = y;
	return true;
}
bool square_2(int x, int y){
	int i,j,len;
	bool S[30][30];
	memset(S, 0, sizeof(S));
	for(i=0; A[x+i][y]; i++);
	len = i;

	for(i=0; i<len; i++)
		for(j=0; j<len-i; j++)
			S[x+j][y-i] = true;
			
	for(i=1; i<=10; i++)
		for(j=1; j<=10; j++)
			if(A[i][j] != S[i][j]) return false;
			
	tri[0][0] = x;
	tri[0][1] = y-len+1;
	tri[1][0] = x;
	tri[1][1] = y;
	tri[2][0] = x+len-1;
	tri[2][1] = y;
	return true;
}
bool square_3(int x, int y){
	int i,j,len;
	bool S[30][30];
	memset(S, 0, sizeof(S));
	for(i=0; A[x][y-i]; i++);
	len = i;

	for(i=0; i<len; i++)
		for(j=0; j<len-i; j++)
			S[x-i][y-j] = true;
			
	for(i=1; i<=10; i++)
		for(j=1; j<=10; j++)
			if(A[i][j] != S[i][j]) return false;
			
	tri[0][0] = x-len+1;
	tri[0][1] = y;
	tri[1][0] = x;
	tri[1][1] = y-len+1;
	tri[2][0] = x;
	tri[2][1] = y;
	return true;
}
bool square_4(int x, int y){
	int i,j,len;
	bool S[30][30];
	memset(S, 0, sizeof(S));
	for(i=0; A[x-i][y]; i++);
	len = i;

	for(i=0; i<len; i++)
		for(j=0; j<len-i; j++)
			S[x-i][y+j] = true;
			
	for(i=1; i<=10; i++)
		for(j=1; j<=10; j++)
			if(A[i][j] != S[i][j]) return false;
	
	tri[0][0] = x-len+1;
	tri[0][1] = y;
	tri[1][0] = x;
	tri[1][1] = y;
	tri[2][0] = x;
	tri[2][1] = y+len-1;
	return true;
}
bool rhombus_1(int x, int y){
	int i,j,len;
	bool S[30][30];
	memset(S, 0, sizeof(S));
	for(i=0; A[x][y+i]; i++);
	len = i;
    
    if(len%2 == 0) return false;

	for(i=0; i<len/2+1; i++)
		for(j=0; j<len-(i*2); j++)
			S[x+i][y+j+i] = true;

	for(i=1; i<=10; i++)
		for(j=1; j<=10; j++)
			if(A[i][j] != S[i][j]) return false;
			
	tri[0][0] = x;
	tri[0][1] = y;
	tri[1][0] = x;
	tri[1][1] = y+len-1;
	tri[2][0] = x+len/2;
	tri[2][1] = y+len/2;
	return true;
}
bool rhombus_2(int x, int y){
	int i,j,len;
	bool S[30][30];
	memset(S, 0, sizeof(S));
	for(i=0; A[x+i][y]; i++);
	len = i;

    if(len%2 == 0) return false;

	for(i=0; i<len/2+1; i++)
		for(j=0; j<len-(i*2); j++)
			S[x+j+i][y-i] = true;
			
	for(i=1; i<=10; i++)
		for(j=1; j<=10; j++)
			if(A[i][j] != S[i][j]) return false;
			
	tri[0][0] = x;
	tri[0][1] = y;
	tri[1][0] = x+len/2;
	tri[1][1] = y-len/2;
	tri[2][0] = x+len-1;
	tri[2][1] = y;
	return true;
}
bool rhombus_3(int x, int y){
	int i,j,len;
	bool S[30][30];
	memset(S, 0, sizeof(S));
	for(i=0; A[x][y-i]; i++);
	len = i;

    if(len%2 == 0) return false;

	for(i=0; i<len/2+1; i++)
		for(j=0; j<len-(i*2); j++)
			S[x-i][y-j-i] = true;
			
	for(i=1; i<=10; i++)
		for(j=1; j<=10; j++)
			if(A[i][j] != S[i][j]) return false;
			
	tri[0][0] = x-len/2;
	tri[0][1] = y-len/2;
	tri[1][0] = x;
	tri[1][1] = y-len+1;
	tri[2][0] = x;
	tri[2][1] = y;
	return true;
}
bool rhombus_4(int x, int y){
	int i,j,len;
	bool S[30][30];
	memset(S, 0, sizeof(S));
	for(i=0; A[x-i][y]; i++);
	len = i;

    if(len%2 == 0) return false;

	for(i=0; i<len/2+1; i++)
		for(j=0; j<len-(i*2); j++)
			S[x-j-i][y+i] = true;
	
	for(i=1; i<=10; i++)
		for(j=1; j<=10; j++)
			if(A[i][j] != S[i][j]) return false;
			
	tri[0][0] = x-len+1;
	tri[0][1] = y;
	tri[1][0] = x-len/2;
	tri[1][1] = y+len/2;
	tri[2][0] = x;
	tri[2][1] = y;
	return true;
}
int main(){
	for(int i=1;i<=10;i++){
		for(int j=1;j<=11;j++){
			char c=getchar();
			if(c=='1') A[i][j] = true;
			if(c=='0') A[i][j] = false;
		}
	}
	
	for(int i=1;i<=10 && !R;i++){
		for(int j=1;j<=10 && !R;j++){
			if(A[i][j] && A[i][j+1]){
				if(square_1(i,j)) R=true;
				if(rhombus_1(i,j)) R=true;
			}
			if(A[i][11-j] && A[i+1][11-j]){
				if(square_2(i,11-j)) R=true;
				if(rhombus_2(i,11-j)) R=true;
			}
			if(A[11-i][11-j] && A[11-i][10-j]){
				if(square_3(11-i,11-j)) R=true;
				if(rhombus_3(11-i,11-j)) R=true;
			}
			if(A[11-i][j] && A[10-i][j]){
				if(square_4(11-i,j)) R=true;
				if(rhombus_4(11-i,j)) R=true;
			}
		}
	}
	
	if(tri[0][0] == 0) printf("0");
	else{
		printf("%d %d\n", tri[0][0],tri[0][1]);
		printf("%d %d\n", tri[1][0],tri[1][1]);
		printf("%d %d\n", tri[2][0],tri[2][1]);
	}
	
	return 0;
}