#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


int bossCount[26];
void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
	// TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	vector<pair<char, bool>> players;
	pair<char,bool> boss = pair<char,bool>('A', false); 
	bossCount[0] = 1;

	for(int i=0; i<numOfAllPlayers-1; i++){
		bool quickPlayer = false;
		for(int j=0; j<numOfQuickPlayers; j++){
			quickPlayer |= 'B'+i == namesOfQuickPlayers[j];
		}
		players.push_back(pair<char, bool>('B' + i, quickPlayer));
	}
	
	cout << "-----" << endl;
	int idx = 0;
	for(int i=0; i<numOfGames; i++){
		cout << boss.first << endl;
		idx += numOfMovesPerGame[i];
		
		if (idx < 0) idx += (numOfAllPlayers-1);
		if (idx >= numOfAllPlayers-1) idx %= numOfAllPlayers-1;

		if(players[idx].second == true){
			bossCount[boss.first - 'A']++;
		}
		else{
			pair<char,bool> temp = players[idx];
			players[idx] = boss;
			boss = temp;
			bossCount[boss.first - 'A']++;
		}
	}
	cout << "-----" << endl;

	for(int i=0; i<numOfAllPlayers-1; i++){
		cout << players[i].first << " " << bossCount[players[i].first -'A'] <<endl;
	}
	cout << boss.first << " " << bossCount[boss.first -'A'] <<endl;
}

struct input_data {
	int numOfAllPlayers;
	int numOfQuickPlayers;
	char *namesOfQuickPlayers;
	int numOfGames;
	int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.numOfAllPlayers;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.numOfQuickPlayers;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
	for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
		iss >> inputData.namesOfQuickPlayers[i];
	}

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.numOfGames;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	inputData.numOfMovesPerGame = new int[inputData.numOfGames];
	for (int i = 0; i < inputData.numOfGames; i++) {
		iss >> inputData.numOfMovesPerGame[i];
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
	return 0;
}