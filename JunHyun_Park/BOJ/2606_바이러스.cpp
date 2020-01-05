#include<cstdio>	// 2606 바이러스 [그래프]
#include<stack>
using namespace std;
int C, N, S=0;
bool visit[101];
class Computer{
public:
	Computer(void){
		this->node = new short[C];
	}
	void nodeConnect(int _n){
		node[top++] = _n;
	}
	~Computer(){
		delete[] this->node;
	}
	short *node;
	short top=0;
};
int main(){
	Computer *com;
	scanf("%d", &C);
	com = new Computer[C];
	for(scanf("%d",&N); N--;){
		int index, node;
		scanf("%d %d", &index, &node);
		com[index -1].nodeConnect(node);
		com[node -1].nodeConnect(index);
	}
	stack<Computer*> sk;

	for(visit[1]=true, sk.push(&com[0]); !sk.empty();){
		for(int i =0; i < sk.top()->top;){
			 if (!visit[sk.top()->node[i]]){
				visit[sk.top()->node[i]] = true;
				sk.push(&com[sk.top()->node[i]-1]);
				S++;
				i = 0;
			 }
			 else i++;
		}
		sk.pop();
	}
	
	printf("%d\n",S);
	delete[] com;	
	return 0;
}