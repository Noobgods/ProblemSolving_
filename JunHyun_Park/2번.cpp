#include <cstdio>
#include <vector>
using namespace std;

long long sum[200003];
long long rev_sum[200003];

int getStatToDelete(vector<int> stats) {
    bool oddEven = 0;
    int i = 2, result = 1, size = stats.size();
    
    for(auto stat : stats){
        sum[i]= sum[i-2] + (long long)stat;
        rev_sum[i] = rev_sum[i-2] + (long long)stats[size-i+1];
        
        i++;
    }

    i = 2;
    for(auto stat : stats){
        if (size%2 != 0){
            if(i%2 == 0){
                if(rev_sum[size-i+2] - rev_sum[size-i+1] + sum[i-2]  - sum[i-1] == 0) return i-1; 
            }
            else {            
                
                if(rev_sum[size-i+1] - rev_sum[size-i+2] + sum[i-1]  - sum[i-2] == 0) return i-1; 
            }
        }
        else{
            if(i%2 == 0){
                if(rev_sum[size-i+2] - rev_sum[size-i+1] + sum[i-2]  - sum[i-1] == 0) return i-1; 
            }
            else {    
                
                if(rev_sum[size-i+1] - rev_sum[size-i+2] + sum[i-1]  - sum[i-2] == 0) return i-1; 
            }
        } 
            
        i++;
    }
    return -1;
}


int main(){
    int N, in;
    vector<int> stats;

    scanf("%d", &N);
    while(N--){
        scanf("%d", &in);
        stats.push_back(in);
    }

    printf("%d", getStatToDelete(stats));

}