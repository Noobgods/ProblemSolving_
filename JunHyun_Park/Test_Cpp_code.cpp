#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool omino[2][2] = {{1,1},{1,1}};
bool imino[1][4] = {1,1,1,1};
bool zmino[2][3] = {{1,1,0},{0,1,1}};
bool lmino[2][3] = {{1,1,1},{0,0,1}};
bool tmino[2][3] = {{1,1,1},{0,1,0}};
int main(){

	int A[2][3] = {{1,1,1}, {1,1,1}};
	int x=0, y=0;
	/*
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			if(A[x+j][y+i] * lmino[j][i] == 1)
				printf("O");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			if(A[x+j][y+2-i] * lmino[j][2-i] == 1)
				printf("O");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			if( A[x+1-j][y+i] * lmino[1-j][i]== 1)
				printf("O");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			if(A[x+1-j][y+2-i] * lmino[1-j][2-i]== 1)
				printf("O");
			else printf(" ");
		}
		printf("\n");
	}
		*/
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			if(A[x+i][y+j] * lmino[i][j] == 1)
				printf("O");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			if( A[x+i][y+2-j] * lmino[i][2-j] == 1)
				printf("O");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			if( A[x+1-i][y+j] * lmino[1-i][j]== 1)
				printf("O");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			if(A[x+1-i][y+2-j] * lmino[1-i][2-j]== 1)
				printf("O");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}

