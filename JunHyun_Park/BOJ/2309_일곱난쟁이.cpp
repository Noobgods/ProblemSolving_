#include<iostream>	// 2309_일곱난쟁이 [브루트포스]
using namespace std;

void swap(int *dwarf);
int i, j;

int main() {
	int dwarf[9];
	int sum = 0;

	for (i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}

	sum -= 100;

	for (i = 0; i < 8; i++)
		for (j = i + 1; j < 9; j++)
			if (sum == (dwarf[i] + dwarf[j])) {
				dwarf[i] = -1;
				dwarf[j] = -1;
				i = 9;
			}

	swap(dwarf);

	for (i = 2; i < 9; i++)
		cout << dwarf[i] << endl;

	return 0;
}

void swap(int *dwarf) {
	for (i = 0; i < 9; i++)
		for (j = 0; j < 8 - i; j++) {
			if (dwarf[j] > dwarf[j + 1]) {
				int temp;

				temp = dwarf[j];
				dwarf[j] = dwarf[j + 1];
				dwarf[j + 1] = temp;
			}
		}
}