#include <iostream> // 1924_2007³â [±¸Çö]
using namespace std;
char *day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main() {
	int x, y;
	cin >> x >> y;
	y -= 1;
	for (int i = x-1; i > 0; i--) {
		switch (i) {
		case 2:
			y += 28; break;
		case 4: case 6: case 9: case 11:
			y += 30; break;
		default:
			y += 31;
		}
	}
	puts(day[y % 7]);
	return 0;
}