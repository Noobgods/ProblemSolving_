#include<cstdio>	// 2042_구간합구하기 [세그먼트트리]
#include<vector>
#include<cmath>
using namespace std;
#define max(x,y) x>y?x:y

/*
세그먼트 트리는 구간합을 빠르게 계산할 수 있도록 저장되어 있는 트리
일반적인 구간합 계산 알고리즘은 연산이 N만큼의 길이로 연산될 경우 O(N)의 속도로 연산되며
연산이 M만큼 반복될 경우 O(NM)의 속도로 연산되지만 세그먼트 트리를 사용할 경우 O(logN)의 속도로 연산된다.

세그먼트 트리는 3가지 함수를 사용
기존의 배열 이외에 세그먼트 트리를 생성하는 생성과정
배열에 값이 추가될 경우 세그먼트 트리를 수정하는 갱신과정
세그먼트 트리를 이용하여 구간합을 계산하는 합과정
*/

int N, M, K;

/** @brief 			세그먼트 트리 생성 과정
 *  @return 		구간 합 계산값
 *  @param a 		값이 저장된 기존 배열
 *  @param tree		저장될 세그먼트 트리
 *  @param node		저장되는 노드 위치
 *  @param start 	현재 노드의 깊이 시작 위치
 *  @param end		현재 노드의 깊이 끝 위치
 */ 
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

/** @brief 			세그먼트 트리 갱신 과정
 *  @param tree		저장된 세그먼트 트리
 *  @param node		갱신되는 노드 위치
 *  @param start 	현재 노드의 깊이 시작 위치
 *  @param end		현재 노드의 깊이 끝 위치
 *  @param index	삽입된 인덱스
 *  @param diff		이전 값과의 차이값
 */ 
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

/** @brief 			세그먼트 트리 합 과정
 *  @param tree		저장된 세그먼트 트리
 *  @param node		갱신되는 노드 위치
 *  @param start 	현재 노드의 깊이 시작 위치
 *  @param end		현재 노드의 깊이 끝 위치
 *  @param left		찾고자 하는 범위 왼쪽
 *  @param right	찾고자 하는 범위 오른쪽
 */
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

    int height = (int)ceil(log2(N));
    int treesize = (1 << (height+1));
    T.assign(treesize, 0);

    init(A, T, 0, 0, N-1);

    for(int i=0; i<M+K; i++){
        int command, option;
        long long int number;
        scanf("%d %d %lld", &command, &option, &number);

        if(command == 1){
            update(T, 0, 0, N-1, option-1, number - A[option-1]);
            A[option-1] = number;
        }
        else if (command == 2)
            printf("%lld\n", sum(T, 0, 0, N-1, option-1, number-1));
    }
}