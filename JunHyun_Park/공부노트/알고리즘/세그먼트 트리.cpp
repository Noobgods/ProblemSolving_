#include<cstdio>	// 2042_구간합구하기 [세그먼트트리]
#include<vector>
#include<cmath>
using namespace std;
#define max(x,y) x>y?x:y

int N, M, K;

// 세그먼트 트리
// - 생성 과정 
long long init(
	vector<long long> &a, 
	vector<long long> &tree,
	int node, int start, int end 
){	
	// 리프 노드일 경우
	if(start == end)
		return tree[node] = a[start];
	
	// 가지 뻗기
	else{
		int mid = (start + end)/2;
		return tree[node] = 
			init(a, tree, node*2+1, start, mid) +
			init(a, tree, node*2+2, mid + 1, end);
	}
}

// - 갱신 과정
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
	// 바꾸고자 하는 인덱스 검사
    if (!(start <= index && index <= end))
        return;
    
	// 인덱스에 차이값 더하기
    tree[node] += diff;
 
	// 가지 뻗기
    if(start != end)
    {
        int mid = (start + end) / 2;
        update(tree, node * 2 + 1, start, mid, index, diff);
        update(tree, node * 2 + 2, mid + 1, end, index, diff);
    }
}

// - 합 과정
long long sum(
	vector<long long> &tree,
	int node, int start, int end, int left, int right
){
	// [left, right] 와 [start, end] 가 전혀 겹치지 않는 경우
	if(left > end || right < start)
		return 0;

	// [left, right] 와 [start, end] 가 서로 범위에 있을 경우
	else if (left <= start && end <= right)
		return tree[node];

	// [left, right] 와 [start, end] 가 일부 겹치는 경우
	else{
		int mid = (start+end)/2;
		return  sum(tree, node*2+1, start, mid, left, right) + 
				sum(tree, node*2+2, mid+1, end, left, right);
	}
}

int main(){
	vector<long long> A, T;
    
    scanf("%d %d %d", &N, &M, &K);
    
    for(int i=1; i<=N; i++){
        long long input;
        scanf("%lld", &input);
        A.push_back(input);
    }

    int h = (int)ceil(log2(N));
    int treesize = (1 << (h+1));
    T.assign(treesize, 0);

    init(A, T, 0, 0, N-1);

    for(int i=0; i<M+K; i++){
        int a, b;
        long long int c;
        scanf("%d %d %lld", &a, &b, &c);

        if(a == 1){
            update(T, 0, 0, N-1, b-1, c - A[b-1]);
            A[b-1] = c;
        }
        else if (a == 2)
            printf("%lld\n", sum(T, 0, 0, N-1, b-1, c-1));
    }
}