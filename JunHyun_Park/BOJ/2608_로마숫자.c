#include <stdio.h>  // 2608_로마숫자 [규칙], [문자열처리]

int strlen(char *str);
int c_rom(char *str, int len);
void c_num(int num);

int i;
char str[20];

int main() {
	char rom1[20], rom2[20];
	int len1, len2;
	int num1, num2;
	int sum;

	scanf("%s", rom1);
	scanf("%s", rom2);

	len1 = strlen(rom1);
	len2 = strlen(rom2);

	num1 = c_rom(rom1, len1);
	num2 = c_rom(rom2, len2);

	sum = num1 + num2;
	c_num(sum);

	printf("%d\n", sum);
	for (i = 0; str[i] != '\0'; i++)
		printf("%c", str[i]);
    
    return 0;
}

int strlen(char *str) {
	for (i = 0; ; i++)
		if (str[i] == '\0')
			return i;
}

int c_rom(char *str, int len) {
	int num = 0;
	for (i = 0; i < len; i++) {
		if ('M' == str[i])
			num += 1000;
		else if ('D' == str[i])
			num += 500;
		else if ('C' == str[i]) {
			if ('M' == str[i + 1]) {
				num += 900;
				i++;
			}
			else if ('D' == str[i + 1]) {
				num += 400;
				i++;
			}
			else
				num += 100;
		}
		else if ('L' == str[i])
			num += 50;
		else if ('X' == str[i]) {
			if ('C' == str[i + 1]) {
				num += 90;
				i++;
			}
			else if ('L' == str[i + 1]) {
				num += 40;
				i++;
			}
			else
				num += 10;
		}
		else if ('V' == str[i])
			num += 5;
		else if ('I' == str[i]) {
			if ('X' == str[i + 1]) {
				num += 9;
				i++;
			}
			else if ('V' == str[i + 1]) {
				num += 4;
				i++;
			}
			else
				num += 1;
		}
	}
	return num;
}

void c_num(int num) {
	for (i = 0; num != 0; i++) {
		if ((num / 1000) >= 1) {
			str[i] = 'M';
			num -= 1000;
		}
		else if ((num / 900) >= 1) {
			str[i] = 'C';
			str[++i] = 'M';
			num -= 900;
		}
		else if ((num / 500) >= 1) {
			str[i] = 'D';
			num -= 500;
		}
		else if ((num / 400) >= 1) {
			str[i] = 'C';
			str[++i] = 'D';
			num -= 400;
		}
		else if ((num / 100) >= 1) {
			str[i] = 'C';
			num -= 100;
		}
		else if ((num / 90) >= 1) {
			str[i] = 'X';
			str[++i] = 'C';
			num -= 90;
		}
		else if ((num / 50) >= 1) {
			str[i] = 'L';
			num -= 50;
		}
		else if ((num / 40) >= 1) {
			str[i] = 'X';
			str[++i] = 'L';
			num -= 40;
		}
		else if ((num / 10) >= 1) {
			str[i] = 'X';
			num -= 10;
		}
		else if ((num / 9) >= 1) {
			str[i] = 'I';
			str[++i] = 'X';
			num -= 9;
		}
		else if ((num / 5) >= 1) {
			str[i] = 'V';
			num -= 5;
		}
		else if ((num / 4) >= 1) {
			str[i] = 'I';
			str[++i] = 'V';
			num -= 4;
		}
		else if ((num / 1) >= 1) {
			str[i] = 'I';
			num -= 1;
			if (num == 0)
				str[i + 1] = '\0';
		}
	}
}
