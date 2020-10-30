#include <string>	// Level2_ 수식 최대화
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

char RANK[6][3] = {
    {'+', '-', '*'},
    {'+', '*', '-'},
    {'-', '+', '*'},
    {'-', '*', '+'},
    {'*', '+', '-'},
    {'*', '-', '+'}
};

long long solution(string expression) {
    long long answer = 0;
    vector<long long> v_operand;
    vector<char> v_operator;
    string n = "";
    
    for(int i=0; i<expression.length(); i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){            
            v_operator.push_back(expression[i]);
            v_operand.push_back(stoi(n));
            n = "";
        }
        else n += expression[i];
    }
    v_operand.push_back(stoi(n));
    n = "";

    for(int i=0; i<6; i++){
    	vector<long long> tmp_num[4];
    	vector<char> tmp_oper[4];
	
    	tmp_num[0] = v_operand;
    	tmp_oper[0] = v_operator;

		stack<long long> s;
        for(int j=0; j<3; j++){
			s.push(tmp_num[j][0]);
            for(int k=0; k<tmp_oper[j].size(); k++){
				if(RANK[i][j] == tmp_oper[j][k]){
					long long a, b;
					if(s.empty()){
						a = tmp_num[j][k];
						b = tmp_num[j][k+1];
					}
					else{
						a = s.top();
						b = tmp_num[j][k+1];
						s.pop();
					}
					if(tmp_oper[j][k] == '+'){
						s.push(a + b);
					}
					if(tmp_oper[j][k] == '-'){
						s.push(a - b);
					}
					if(tmp_oper[j][k] == '*'){
						s.push(a * b);
					}
				}
				else {
					if(!s.empty()){
						tmp_num[j+1].push_back(s.top());
						s.pop();
					}
					else {
						tmp_num[j+1].push_back(tmp_num[j][k]);
					}
					tmp_oper[j+1].push_back(tmp_oper[j][k]);
				}
            }
			if(!s.empty()){
				tmp_num[j+1].push_back(s.top());
				s.pop();
			}
			else{
				tmp_num[j+1].push_back(tmp_num[j][tmp_oper[j].size()]);
			}
        }
		answer = max(llabs(tmp_num[3][0]),answer);
    }
    return answer;
}

int main(){
	string expression;
	getline(cin, expression);

	cout << solution(expression);
	return 0;
}