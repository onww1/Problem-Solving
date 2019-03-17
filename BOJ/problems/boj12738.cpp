#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int BUFFER_SIZE = 1 << 17;
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
inline int readInt() {
	int sum = 0, flag = 0;
	char now = read();
	while (now == ' ' || now == '\n') now = read();
	if (now == '-') flag = 1, now = read();
	while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
	return flag ? -sum : sum;
}

vector <int> lis;
int N, A;
int main() {
	N = readInt();
	A = readInt();
	lis.push_back(A);
	for (int i = 1; i < N; ++i) {
		A = readInt();
		if (lis.back() < A) lis.push_back(A);
		else {
			auto it = lower_bound(lis.begin(), lis.end(), A);
			*it = A;
		}
	}
	return !printf("%lu\n", lis.size());
}