#include<cstdio>    // 18870_좌표압축 [정렬]
int N;
int arr_x[1000001], rst_idx[1000001], rst[1000001];

void swap(int a, int b){
    int t = rst_idx[a];
    rst_idx[a] = rst_idx[b];
    rst_idx[b] = t;
}

void sort(int first, int last){
    int i=first, j=last;
    int idx =  rst_idx[(first + last)/2];
    while(i<=j){
        while(arr_x[rst_idx[i]] < arr_x[idx]) i++;
        while(arr_x[rst_idx[j]] > arr_x[idx]) j--;
        if(i<=j){
            swap(i++, j--);
        }
    }

    if(first < j) sort(first, j);
    if(i < last) sort(i, last);
}

int main(){
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &arr_x[i]);
        
        rst_idx[i] = i;
    }
    
    sort(0, N-1);

    int red = 0;
    rst[rst_idx[0]] = 0;
    for(int i=1; i<N; i++){
        if (arr_x[rst_idx[i]] == arr_x[rst_idx[i-1]]) red++;
        rst[rst_idx[i]] = i-red;
    }


    for(int i=0; i<N; i++)
        printf("%d ", rst[i]);

    return 0;
}