#include<iostream>
#include<vector>
#include<memory>
#include<functional>
using namespace std;

namespace Algorithm{
    template<typename T>
    void print(T A){
        std::function<void()> func = [&](){
            for(auto i : A){
                std::cout<<i.first <<" " <<i.second<<endl;
            }
        };
        /* 위와 같음
        for(auto i = A.begin(); i!= A.end(); i++){
            std::cout<< i->first <<" " <<i->second << endl;
        }
        */
        func();
    }
    template<typename _T1, typename _T2>
    class temp{
        public:
        _T1 first;
        _T2 second;
        temp(_T1 first_, _T2 second_) :first(first_), second(second_){}; 
        temp& operator=(temp const& rhs){
            this->first = rhs.fisrt;
            this->second = rhs.second;
            return *this;
        }
    };
}

int main(){
    unique_ptr<vector<Algorithm::temp<int, string>>> A;
    A = make_unique<vector<Algorithm::temp<int, string>>>();

    for(int i=0;i<10; i++){
        A->push_back(Algorithm::temp<int, string>(i, "와우"));
    }
    
    Algorithm::print(*A);
    return 0;
}