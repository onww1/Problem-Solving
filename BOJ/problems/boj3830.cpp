#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 1e5;
const int INF = 0x7f7f7f7f;

pii pa[MAX + 1];

pii _find(int a) {
	if (pa[a].first < 0) return { a, 0 };
	pii root = _find(pa[a].first);
	return pa[a] = { root.first, root.second + pa[a].second };
}

int main(int argc, char *argv[]) {
	int n, m, a, b, w; char c;
	while (true) {
		scanf("%d %d", &n, &m);
		if (!n && !m) break;

		memset(pa, -1, sizeof(pa));
		while (m--) {
			scanf(" %c %d %d", &c, &a, &b);
			pii a_root = _find(a);
			pii b_root = _find(b);

			if (c == '!') {
				scanf("%d", &w);
				if (a_root.first != b_root.first) {
					if (a_root.second - b_root.second > w) 
						pa[b_root.first] = { a_root.first, a_root.second - b_root.second - w };
					else 
						pa[a_root.first] = { b_root.first, b_root.second - a_root.second + w };
				}
			}
			else {
				if (a_root.first == b_root.first) printf("%d\n", a_root.second - b_root.second);
				else puts("UNKNOWN");
			}
		}
	}
	return 0;
}