#include <cstdio>
#include <cstring>
typedef long long ll;

const int BUFFER_SIZE = 1 << 20;
char buf[BUFFER_SIZE];
inline char read() {
	static int idx = BUFFER_SIZE;
	if (idx == BUFFER_SIZE) {
		int nidx = fread(buf, 1, BUFFER_SIZE, stdin);
		if (!nidx) return 0;
		idx = 0;
	}
	return buf[idx++];
}
inline ll readLL() {
	ll sum = 0;
	char now = read();
	while (now == ' ' || now == '\n') now = read();
	while ('0' <= now && now <= '9') sum = sum * 10LL + now - '0', now = read();
	return sum;
}

int main() {
	ll N = 0, S = 0;
	N = readLL();
	for (int i = 0 ; i < N; ++i) 
		S += readLL();
	printf("%lld\n%lld\n", N, S);
	return 0;
}