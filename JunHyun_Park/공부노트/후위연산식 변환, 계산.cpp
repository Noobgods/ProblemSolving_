#include<cstdio>	// 괄호만을 고려한 연산. [후위연산식 변환], [후위연산식 계산]
template <typename T>
class stack{
public:
	void push(T n){
		this->_n[++_top] = n;
	}
	int pop(){
		return this->_n[_top--];
	}
	int top(){
		if(this->isEmpty()) return -1;
		else return this->_n[_top];
	}
	bool isEmpty(){
		if(_top == -1)	return true;
		else	return false;
	}
	int isTop(){
		return _top;
	}	
private:
	T _n[20];
	int _top = -1;
};

int main(){
	short N, top = -1;	// 문자 갯수, 후위 변환 문자열의 길이
	char c, s[20];	// 입력 문자 , 후위 변환 문자열
	stack<int> n_s;	// 피연산자 스택 
	stack<char> oper;	// 연산자 스택

	scanf("%d ", &N);
	
	for(int i=0; i<N; i++){
		scanf("%c", &c);
		
		if(c >= '0' && c <= '9') s[++top] = c;	// 피연산자
		else if(c == '(') 	// 여는 괄호
			oper.push(c);

		else if(c == '*' || c == '+' || c == '-') {	// 연산자
			if(!oper.isEmpty() && oper.top() != '(') // 비어있지 않고 스택에 있는것이 괄호가 아니면
				s[++top] = oper.pop();	// 괄호조건을 연산자 우선순위에 맞추어 다른 조건을 지정하면 우선순위 지정 가능
			oper.push(c);
		}
		else if(c == ')'){
			while(oper.top() != '(')	// 괄호가 나올때 까지 연산자를 pop (다른 조건 적용시 연산자 우선순위)
				s[++top] = oper.pop();
			oper.pop();
		}
	}

	// 스택 비우기
	while(!oper.isEmpty()) s[++top] = oper.pop();
	s[++top] = '\0';
	
	// 후위 연산식 출력
	printf("%s\n", s);
	
	// 후위 연산식 계산
	for(int i=0; s[i] != '\0'; i++){
		int a, b;
		if(s[i] == '+') n_s.push(n_s.pop() + n_s.pop());
		else if(s[i] == '-') {
			b = n_s.pop();
			a = n_s.pop();
			n_s.push(a - b);
		}
		else if(s[i] == '*') n_s.push(n_s.pop() * n_s.pop());
		else n_s.push(s[i] - '0');
	}
	printf("%d", n_s.top());
	return 0;
}