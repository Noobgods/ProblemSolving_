#include <cstdio>	// 1343_폴리오미노 [그리디]
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	getline(cin, s);

	for(int i=0; i<(int)s.length()-3;){
		if(s.substr(i, 4) == "XXXX"){
			s.replace(i, 4, "AAAA");
			i+=4;
		}
		else if(s[i]=='X') i+=2;
		else i++;
	}
	for(int i=0;i<(int)s.size()-1;){
		if(s.substr(i, 2) == "XX"){
			s.replace(i, 2, "BB");
			i+=2;
		}
		else if(s[i]=='X') i+=2;
		else i++;
	}
	if(s.find('X') != string::npos) printf("-1");
	else printf("%s", s.c_str());
	return 0;
}