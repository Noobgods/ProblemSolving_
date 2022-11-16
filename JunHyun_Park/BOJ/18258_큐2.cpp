#include<cstdio>  // 18258 큐2 [큐]
#include<cstring>
using namespace std;

struct Q{
    int s[2000000];
    int front_=0, back_=0;
    int pop(){
        if(this->empty()) return -1;
        else {
            int temp = this->front();
            front_ = (front_+1)%2000000;
            return temp;
        }
    }
    void push(int n){
        back_ = (back_+1)%2000000;
        s[back_] = n; 
    }
    int front(){
        if(this->empty()) return -1;
        return s[front_+1];
    }
    int back(){
        if(this->empty()) return -1;
        return s[back_];
    }
    bool empty(){
        if(front_ == back_) return 1;
        else return 0;
    }
    int size(){
        return back_ - front_;
    }
};

int main(){
    int N;
    Q que;
    for(scanf("%d",&N); N--;){
        char s[10];
        scanf("\n%s",s);
        if(strcmp(s,"push") ==0){
            int n;
            scanf("%d",&n);
            que.push(n);
        }
        if(strcmp(s,"pop") ==0) 
            printf("%d\n",que.pop());
        if(strcmp(s,"size") ==0) 
            printf("%d\n",que.size());
        if(strcmp(s,"empty") ==0) 
            printf("%d\n",que.empty());
        if(strcmp(s,"front") ==0) 
            printf("%d\n",que.front());
        if(strcmp(s,"back") ==0)
            printf("%d\n",que.back());
    }
    return 0;
}