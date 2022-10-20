#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


#define CUT 100000007

int dd[28];
int getMaximumCombatPower(string adventures, int k) {
    int max = 0;
    for(int i=0; i<k; i++){
        dd[adventures[i]-96]++;
    }

    for(int i=0; i<=adventures.length()-k; i++){
        long long result = 0;
        for(int j=1; j<27; j++){
            if(dd[j] > 0)
                result = result + (long long)pow(j, dd[j])%CUT;
        }
        if (max < result) max = result%CUT;
        
        if(i+1<=adventures.length()-k){
            dd[adventures[i]-96]--;
            dd[adventures[k+i]-96]++;
        }
    }
    return max;
}

int main(){
    int N, in;
    string adv;

    cin >> adv;
    cin >> N;

    printf("%d", getMaximumCombatPower(adv, N));

}