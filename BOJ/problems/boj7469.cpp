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

const int SZ = 1 << 17;
const int MAX = 1e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
const int move_c[] = { 0, -1, 0, 1, -1, 1, -1, 1 };

int N, M, A[SZ], idx[MAX];
vector <int> tree[2 * SZ];

vector <int> init(int node, int start, int end);
int count(int node, int start, int end, int left, int right, int x);

int main(int argc, char *argv[]) {
	open();

	N = readInt(), M = readInt();
	for (int i = 0; i < N; ++i) A[i] = readInt(), idx[i] = A[i];
	sort(idx, idx + N);
	for (int i = 0; i < N; ++i) A[i] = lower_bound(idx, idx + N, A[i]) - idx;
	init(1, 0, N - 1);

	int a, b, k;
	while (M--) {
		a = readInt(), b = readInt(), k = readInt();
		int l = 0, r = N - 1, m, cnt, ans;
		while (l <= r) {
			m = (l + r) / 2;
			cnt = count(1, 0, N - 1, a - 1, b - 1, m);
			if (cnt >= k) {
				r = m - 1;
				ans = m;
			}
			else l = m + 1;
		}
		printf("%d\n", idx[ans]);
	}

	return 0;
}

vector <int> init(int node, int start, int end) {
	if (start == end) {
		tree[node].push_back(A[start]);
		return tree[node];
	}

	int mid = (start + end) / 2;
	vector <int> left = init(node * 2, start, mid);
	vector <int> right = init(node * 2 + 1, mid + 1, end);
	
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (left[l] == right[r]) {
			tree[node].push_back(left[l++]);
			tree[node].push_back(right[r++]);
		}
		else if (left[l] < right[r]) tree[node].push_back(left[l++]);
		else tree[node].push_back(right[r++]);
	}
	while (l < left.size()) tree[node].push_back(left[l++]);
	while (r < right.size()) tree[node].push_back(right[r++]);
	return tree[node];
}

int count(int node, int start, int end, int left, int right, int x) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) {
		int idx = lower_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
		if (idx < end - start + 1 && tree[node][idx] == x) return idx + 1;
		return idx;
	}
	int mid = (start + end) / 2;
	return count(node * 2, start, mid, left, right, x) +
		   count(node * 2 + 1, mid + 1, end, left, right, x);
}