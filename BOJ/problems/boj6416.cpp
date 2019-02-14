#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pii;

map <int, int> idx;
vector < vector<int> > edges;
vector <int> in;

int main(int argc, char *argv[]) {
	int u, v, k = 1, index = 1;
	while (true) {
		scanf("%d %d", &u, &v);
		if (u == -1 && v == -1) break;

		if (u == 0 && v == 0) {
			printf("Case %d is a tree.\n", k++);
			continue;
		}

		idx.clear(); 
		in.resize(1);
		edges.resize(1);
		index = 1;

		while (true) {
			if (!u && !v) break;

			if (idx[u] == 0) {
				idx[u] = index++;
				edges.push_back(vector<int>());
				in.push_back(0);
			}
			if (idx[v] == 0) {
				idx[v] = index++;
				edges.push_back(vector<int>());
				in.push_back(0);
			}
			edges[idx[u]].push_back(idx[v]);
			in[idx[v]]++;
			scanf("%d %d", &u, &v);
		}

		int root = -1, valid = 1;
		for (int i = 1; i < in.size(); ++i) {
			if (in[i] == 0) {
				if (root != -1) {
					valid = 0;
					break;
				}
				root = i;
			}
			else if (in[i] > 1) {
				valid = 0;
				break;
			}
		}

		if (!valid) {
			printf("Case %d is not a tree.\n", k++);
			continue;
		}

		in[root] = 0;
		queue <int> q; q.push(root);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int next : edges[cur]) {
				if (in[next]) {
					in[next] = 0;
					q.push(next);
				}
			}
		}

		for (int i = 1; i < index; ++i) if (in[i]) valid = 0;
		printf("Case %d is %s\n", k++, valid ? "a tree." : "not a tree.");
	}
	return 0;
}

