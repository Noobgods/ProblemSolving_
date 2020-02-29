#include<cstdio>    // 10866_µ¦ [µ¦]
#include<cstring>
using namespace std;

struct DQ{
    int s[100000];
    int front_=50000, back_=50000;
    int pop_back(){
        if(this->empty())   return -1;
        else {
            int temp = this->back();
            back_ = back_-1;
            return temp;
        }
    }
    int pop_front(){
        if(this->empty())  return -1;
        else {
            int temp = this->front();
            front_ = front_+1;
            return temp;
        }
    }
    void push_back(int n){
        back_ = back_+1;
        s[back_] = n; 
    }
    void push_front(int n){
        s[front_] = n; 
        front_ = front_-1;
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
    DQ que;
    for(scanf("%d",&N); N--;){
        char s[10];
        scanf("\n%s",s);
        if(strcmp(s,"push_back") ==0){
            int n;
            scanf("%d",&n);
            que.push_back(n);
        }
        if(strcmp(s,"push_front") ==0){
            int n;
            scanf("%d",&n);
            que.push_front(n);
        }
        if(strcmp(s,"pop_front") ==0) 
            printf("%d\n",que.pop_front());
        if(strcmp(s,"pop_back") ==0) 
            printf("%d\n",que.pop_back());
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