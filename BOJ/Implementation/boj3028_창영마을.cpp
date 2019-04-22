#include <stdio.h>

char cmd[51]; 
int pos = 1;
int main() {
	scanf(" %s", &cmd);
	for (int i = 0; cmd[i]; ++i) {
		if (cmd[i] == 'A' && pos != 3) pos = 3 - pos;
		else if (cmd[i] == 'B' && pos != 1) pos = 5 - pos;
		else if (cmd[i] == 'C' && pos != 2) pos = 4 - pos; 
	}
	printf("%d\n", pos);
	return 0;
}