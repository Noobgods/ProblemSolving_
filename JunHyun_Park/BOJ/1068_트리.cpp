#include<cstdio>    // 1068_트리 [트리]
#include<list>
using namespace std;

struct Tree {
	int p;
    int size=0;   
    Tree* leef[51];
    void push_back(Tree* lf){
        leef[size++] = lf;
    }
    void remove(Tree *lf){
        for(int i=0; i<size; i++){
            if(lf == leef[i]) {
                leef[i] = NULL;
                this->size--;
                for(int j=i; j<size-1; j++){
                    leef[i] = leef[i+1];
                }
            }
        }
    }
};

Tree tree[51];

bool search(int n){
    if(tree[n].p == -1) return true;
    if(tree[n].p == -2) return false;
    else {return search(tree[n].p);}
}

int main() {
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d", &tree[i].p);
        if(tree[i].p != -1)tree[tree[i].p].push_back(&tree[i]);
	}
    int delnode;
    scanf("%d", &delnode);
    tree[tree[delnode].p].remove(&tree[delnode]);
    tree[delnode].p = -2;

    int R = 0;
    for(int i=0; i<n; i++){
        if(search(i) && tree[i].size == 0) R++;
    }

    printf("%d", R);
	return 0;
}