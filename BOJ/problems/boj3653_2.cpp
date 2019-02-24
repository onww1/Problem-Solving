#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;

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
	int sum = 0, flg = 1;
	char now = read();
	while (now == ' ' || now == '\n') now = read();
	if (now == '-') flg = 0, now = read();
	while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
	return flg ? sum : -sum;
}
inline ll readLL() {
	ll sum = 0, flg = 1;
	char now = read();
	while (now == ' ' || now == '\n') now = read();
	if (now == '-') flg = 0, now = read();
	while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
	return flg ? sum : -sum;
}

void open() {
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
}

const int MAX = 1e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
const int move_c[] = { 0, -1, 0, 1, -1, 1, -1, 1 };

int T, N, M, A[MAX + 1], tree[2 * MAX + 1];

void update(int node, int diff);
int sum(int node);

int main(int argc, char *argv[]) {
	open();

	T = readInt();
	while (T--) {
		N = readInt(), M = readInt();
		memset(tree, 0, sizeof(tree));
		for (int i = N; i > 0; --i) {
			A[N + 1 - i] = i;
			update(i, 1);
		}
		
		int P;
		for (int i = 1; i <= M; ++i) {
			P = readInt();
			printf("%d ", N - sum(A[P]));
			update(A[P], -1);
			A[P] = N + i;
			update(A[P], 1);
		}

		puts("");
	}

	return 0;
}

void update(int node, int diff) {
	while (node <= N + M) {
		tree[node] += diff;
		node += node & -node;
	}
}

int sum(int node) {
	int ret = 0;
	while (node > 0) {
		ret += tree[node];
		node -= node & -node;
	}
	return ret;
}