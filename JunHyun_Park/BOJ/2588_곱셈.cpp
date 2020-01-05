#include<cstdio>    // 2588_°ö¼À [¼öÇĞ], [±¸Çö]
int main(void){
	int a, b;
	int result;
	int answer1, answer2, answer3;
	int b_array[3];

	scanf("%d%d",&a,&b);
    
	b_array[2] = b % 10;
	b /= 10;
	b_array[1] = b % 10;
	b /= 10;
	b_array[0] = b % 10;

	answer1 = b_array[2] * a;
	answer2 = b_array[1] * a;
	answer3 = b_array[0] * a;
    
    result = answer1 + (answer2 * 10) + (answer3 * 100);
    
	printf("%d\n",answer1);
	printf("%d\n",answer2);
	printf("%d\n",answer3);
	printf("%d\n",result);

	return 0;
}