#include <cstdio>
int N, G, B;
char name[50];
int main() {
	scanf("%d", &N);
	getchar();
	while (N--) {
		fgets(name, sizeof(name), stdin);

		G = B = 0;
		for (int i = 0; name[i]; ++i) 
			if (name[i] == 'G' || name[i] == 'g') G++;
			else if (name[i] == 'B' || name[i] == 'b') B++;
			else if (name[i] == '\n') name[i] = 0;
		printf("%s is %s\n", name, G > B ? "GOOD" : G < B ? "A BADDY" : "NEUTRAL");
	}
	return 0;
}