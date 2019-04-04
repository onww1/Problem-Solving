#include <cstdio>
#include <vector>
using namespace std;

char buf[1 << 17];
inline char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		int nidx = fread(buf, 1, 1 << 17, stdin);
		if (!nidx) return 0;
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0, flg = 1;
	char now = read();
	while (now == ' ' || now == '\n') now = read();
	if (now == '-') flg = 0, now = read();
	while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
	return flg ? sum : -sum;
}

vector <int> color[200001];

int main(int argc, char *argv[]) {
	int n, c, s, i;
	n = readInt();
	for (i = 0; i < n; ++i) {
		c = readInt();
		s = readInt();

	}
}