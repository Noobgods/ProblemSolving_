#include<iostream>  // 11286_절댓값힙 [힙]
#include<queue>
#include<vector>
#include<functional> 
#include<math.h>

using namespace std;

int main() {
	priority_queue<int, vector<int>, less<int> > max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (max_heap.empty() && min_heap.empty()) cout << 0 << endl;
			else if (max_heap.empty()) {
				cout << min_heap.top() << endl;
				min_heap.pop();
			}
			else if (min_heap.empty()) {
				cout << max_heap.top() << endl;
				max_heap.pop();
			}
			else {
				if (abs(max_heap.top()) > abs(min_heap.top())) {
					cout << min_heap.top() << endl;
					min_heap.pop();
				}
				else {
					cout << max_heap.top() << endl;
					max_heap.pop();
				}
			}
		}
		else if (x > 0) min_heap.push(x);
		else			max_heap.push(x);
	}
	return 0;
}