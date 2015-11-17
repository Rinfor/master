#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define ESC 27

int main() {
	bool esEsc=false;
	char mundo[] = "*****+**********************************************************************";
	int len = strlen(mundo);
	int coorXPj = 5;
	int coorXBala = 5;
	int intChar;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	while (!esEsc) {
		printf("%s\r", mundo);
		if (_kbhit() != 0) {
			intChar = _getch();
			if (intChar == ESC)
				esEsc = true;
			else {
				char charPress = static_cast<char>(intChar);
				mundo[coorXPj] = '*';
				if (charPress == 'd' && coorXPj < len - 1)
					coorXPj++;
				else if (charPress == 'a' && coorXPj > 0)
					coorXPj--;
				else if (charPress == 'l' && coorXPj!=len-1) {
					for (int i = coorXBala + 1; i < len; i++) {
						coorXBala = coorXPj + 1;
						mundo[i] = '>';
						mundo[i - 1] = '*';
						printf("%s\r", mundo);
						mundo[coorXPj] = '+';
						Sleep(50);
					}		
					mundo[len-1] = '*';
				}
				mundo[coorXPj] = '+';
			}
		}
	}

	return 0;
}