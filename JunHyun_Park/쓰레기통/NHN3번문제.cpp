#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

string f(string order){
	stack<int> s;
	string ord;
	int repeat =-1;
	int idx = 0;
	for(int i=0, k=0; i<order.length(); i++){
		if(order[i] >= '1' && order[i] <= '9') {
			if(order[i+1] > 'A'){
				repeat = ord[idx-1] -'0';
				for(int j=0; j<)
			}
			ord += order[i];
		}
		else if(order[i] == '(') {
			s.push(i);
			ord += '(';
		}
		else if(order[i] == ')'){
			idx = s.top();
			s.pop();
			string str;
			str = ord.substr(idx+1, i);

			repeat = ord[idx-1] -'0';
			ord.erase(idx-1, i);
			for(int j=0; j<repeat; j++){
				ord += str;
			}
		}
		else{
			ord += order[i];
		}
	}
	return ord;
}
void solution(int numOfOrder, string *orderArr) {
	// TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	for(int i=0; i<numOfOrder; i++){
		cout << f(orderArr[i]) << endl;

	}
}

struct input_data {
	int numOfOrder;
	string *orderArr;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.numOfOrder;

	inputData.orderArr = new string[inputData.numOfOrder];
	for (int i = 0; i < inputData.numOfOrder; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		iss >> inputData.orderArr[i];
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.numOfOrder, inputData.orderArr);
	return 0;
}