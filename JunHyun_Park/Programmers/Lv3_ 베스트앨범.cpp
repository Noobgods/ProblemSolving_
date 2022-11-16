#include <string>   // Level3_ 베스트 앨범 [해시]
#include <vector>
#include <map>
#include <algorithm>

#include <iostream>
using namespace std;
struct genre{
    genre(int _idx, int _plays){
        plays.push_back(make_pair(_idx, _plays));
        sumPlays = _plays;
    }
    vector<pair<int, int>> plays;
    int sumPlays = 0;
};

bool cmp(const pair<string, genre>& a, const pair<string, genre>& b){
    return a.second.sumPlays > b.second.sumPlays;
}

bool cmp_genre(const pair<int, int>& a, const pair<int, int>& b){
    if (a.second == b.second ) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, genre> albums;

    for(int i=0; i<genres.size(); i++){
        auto album = albums.find(genres[i]);
        if(album == albums.end()){
            albums.insert(make_pair(genres[i], genre(i, plays[i])));           
        }
        else
        {
            album->second.sumPlays += plays[i];
            album->second.plays.push_back(make_pair(i, plays[i]));
        }
    }
    vector<pair<string, genre>> v_albums(albums.begin(), albums.end());

    sort(v_albums.begin(), v_albums.end(), cmp);
    
    for(int i=0; i<v_albums.size(); i++){
        sort(v_albums[i].second.plays.begin(), v_albums[i].second.plays.end(), cmp_genre);
    }

    for(int i=0; i<v_albums.size(); i++){
        int k =0;
        for(int j=0; j<v_albums[i].second.plays.size() && k<2; j++, k++){
            answer.push_back(v_albums[i].second.plays[j].first);
        }
    }

    return answer;
}

int main(){
    int n;
    cin >> n;
    vector<string> genres;
    vector<int> plays;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        genres.push_back(s);
    }
    
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        plays.push_back(k);
    }
 
    vector<int> sol = solution(genres, plays); 
    for(auto k : sol){
        cout << k << " ";
    }
    return 0;
}