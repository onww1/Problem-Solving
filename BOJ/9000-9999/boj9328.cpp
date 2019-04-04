#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct point {
	int r, c;
};

int T, H, W, doc;
char map[100][101];
bool key[26];
vector<point> entrance;

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if (r < 0 || r >= H || c < 0 || c >= W) return false;
	return true;
}

void init() {
	scanf("%d %d", &H, &W);
	for (int i=0; i<H; i++) 
		scanf("%s", map[i]);

	memset(key, 0, 26);
	char keys[27];
	scanf("%s", keys);
	if (keys[0] != '0') {
		int len = strlen(keys);
		for (int i=0; i<len; i++) {
			key[keys[i] - 'a'] = 1;
		}
	}

	entrance.clear();
	for (int j=0; j<W; j++) {
		if (map[0][j] != '*') entrance.push_back({0, j});
		if (map[H-1][j] != '*') entrance.push_back({H-1, j});
	}
	for (int i=1; i<H-1; i++) {
		if (map[i][0] != '*') entrance.push_back({i, 0});
		if (map[i][W-1] != '*') entrance.push_back({i, W-1});
	}

	doc = 0;
}

bool solve(point& entrance) {
	queue<point> q;
	bool visited[100][100] = {false, };
	q.push(entrance);
	visited[entrance.r][entrance.c] = true;

	bool getKey = false;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		if (map[r][c] == '$') {
			doc++;
			map[r][c] = '.';
		}
		else if ('A' <= map[r][c] && map[r][c] <= 'Z') {
			if (!key[map[r][c] - 'A']) 
				continue;
		}
		else if ('a' <= map[r][c] && map[r][c] <= 'z') {
			getKey = true;
			key[map[r][c] -'a'] = 1;
			map[r][c] = '.';
		}

		for (int k=0; k<4; k++) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if (check(dr, dc) && !visited[dr][dc] && map[dr][dc] != '*') {
				q.push({dr, dc});
				visited[dr][dc] = true;
			}
		}
	}
	return getKey;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &T);
	
	while (T--) {
		init();

		bool getKey = true;
		while (getKey) {
			getKey = false;
			int len = entrance.size();
			for (int i=0; i<len; i++) {
				getKey = getKey || solve(entrance[i]);
			}
		}

		printf("%d\n", doc);
	}

	return 0;
}