#include<cstdio>    // 8912_Sales [±ÔÄ¢]
int T, n, a[1001], b[3], r;
int main(){
	scanf("%d", &T);
	while(T--){
		r = 0, b[2] = 1;
		scanf("%d", &n);

		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
			if(i==0) b[0] = b[1] = a[0];
			else {
				if (b[0] == a[i]){
					r += b[2];
					b[2]++;
				}
				else if(b[0] > a[i]) {
					b[0] = a[i];
					b[2] = 1;
				}
				else if(b[1] <= a[i]) {
					b[1] = a[i]; 
					r += i;
				}
				else for(int j=0; j<i; j++)
					if(a[j] <= a[i]) r++;
			}	
		}
		printf("%d\n",r);
	}
	
	return 0;
}