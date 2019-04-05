#include <cstdio>
char in[102], o[101];
int idx;
int main() {
	fgets(in, sizeof(in), stdin);
	for (int i = 0; in[i]; ++i) {
		if (in[i] == '\n') {
			o[idx] = 0;
			break;
		}
		if (in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u') {
			o[idx++] = in[i];
			i += 2;
		}
		else o[idx++] = in[i];
	}
	return !printf("%s\n", o);
}