#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int tower[101];

void solution(int day, int width, int **blocks) {
	int max = 0;
	int answer = 0;
  	for(int i=0; i<day; i++){
		for(int j=0; j<width; j++){
			tower[j] += blocks[i][j];
		}

		max = 0; 
		for(int j=1; j<width-1; j++){
			if (tower[j] > tower[max]) {
				for(int k = max; k < j; k++){
					answer += tower[max] - tower[k];
					tower[k] = tower[max];
				}
				max = j;
			}
			if (tower[j] > tower[j+1]){
				for(int k = max+1; k < j; k++){
					answer += tower[j] - tower[k];
					tower[k] = tower[j];
				}
			}
		}

		
	}

	cout << answer;
}

struct input_data {
	int day;
	int width;
	int **blocks;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.day;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.width;

	inputData.blocks = new int*[inputData.day];
	for (int i = 0; i < inputData.day; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.blocks[i] = new int[inputData.width];
		for (int j = 0; j < inputData.width; j++) {
		iss >> inputData.blocks[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}