#include <iostream>
#include <cstdio>
#include <cstring>

int n;
int cnt = 0;
int arr[35];
int carry[35];
void TwoLargeInteger(int multiNum,int start)
{
	int tmp;
	int ret;
	arr[34] = start;
	for(int i=0; i<multiNum; i++)
	{
		memset(carry,0,sizeof(int) * 35);
		for(int j=34; j>=1; j--)
		{	
			tmp = 2*arr[j];
			if(tmp >= 10)
			{
				carry[j-1]++;
				arr[j] = tmp - 10;
			}
			else
				arr[j] = tmp;
		}
		for(int m=33; m>=0; m--)
				arr[m] += carry[m];
	}
	if(arr[34] != 0)
	{
		arr[34] -= 1;
		return;
	}
	else
	{
		for(int j=34; j>=1; j--)
		{	
			if(arr[j]  >= 0)
			{
				arr[j] -= 1;
				break;
			}
			else
			{
				arr[j] += 9;
				arr[j-1] -= 1;
				
			}
		}
	}
}
void Hanoi(int num, int start, int middle, int last)
{
	//printf("n: %d\n",num);
	if(num == 1)
	{
		printf("%d %d\n",start,last);
		return;
	}
	Hanoi(num-1,start,last,middle);
	printf("%d %d\n",start,last);
	Hanoi(num-1,middle,start,last);
	
	
}

int main(void)
{
	scanf("%d",&n);
	int data = 1;
	for(int i=0; i<n; i++)
		data*=2;
	for(int i=0; i<35; i++)
		arr[i] = 0;
	if(n <= 20)
	{
		printf("%d\n",data-1);
		Hanoi(n,1,2,3);
	}
	else
	{
		TwoLargeInteger(n,1);
		int i=0;
		while(arr[i] == 0)
			i++;
		for(int j = i; i<=34; i++)
			printf("%d",arr[i]);
		
	}
	return 0;
}