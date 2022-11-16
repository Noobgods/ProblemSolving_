#include <string>   // Level2_ 전화번호 목록 [해쉬]
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    for(int i=0; i<phone_book.size(); i++){
        for(int j=0; j<phone_book.size(); j++){
            if( i!= j){
                bool bl = true;
                if (phone_book[i].length() > phone_book[j].length()) continue;
                for(int k=0; k<phone_book[i].length(); k++){
                    if(phone_book[i][k] != phone_book[j][k]){
                        bl = false;
                        break;
                    }
                if(bl) { return false;}
            }
        }
    }
    return answer;
}