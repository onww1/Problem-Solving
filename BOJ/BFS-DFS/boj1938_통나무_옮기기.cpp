#include <stdio.h>

template <typename T>
class queue {
public:
	queue() { 
		_head = _tail = 0;
		_capacity = 2500;
		_data = new T[_capacity];
	}
	~queue() { delete []_data; }
	void push(T item) { 
		if ((_tail + 1) % _capacity == _head) 
			throw "FULL";
		_tail = (_tail + 1) % _capacity;
		_data[_tail] = item;
	}
	void pop() { _head = (_head + 1) % _capacity; }
	T front() { return _data[(_head + 1) % _capacity];}
	int size() { return (_tail - _head + _capacity) % _capacity; }
	bool empty() { return _head == _tail; }
private:
	T* _data;
	int _head, _tail, _capacity;
};

struct pair {
	int r, c, d, t;
	pair(): r(0), c(0), d(0), t(0) {}
	pair(int _r, int _c, int _d, int _t): r(_r), c(_c), d(_d), t(_t) {}
};

const int MAX = 50;
const int move_r[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
const int move_c[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
int N; pair dst;
char MAP[MAX][MAX + 1];
bool visited[2][MAX][MAX]; // 0 : 가로, 1 : 세로

bool can_I_go(int r, int c, int d) {
	if (d && r - 1 >= 0 && r + 1 < N) return !((MAP[r - 1][c] - '0') || (MAP[r][c] - '0') || (MAP[r + 1][c] - '0'));
	else if (!d && c - 1 >= 0 && c + 1 < N) return !((MAP[r][c - 1] - '0') || (MAP[r][c] - '0') || (MAP[r][c + 1] - '0'));
	return false;
}

int main(int argc, char *argv[]) {
	queue <pair> q;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) 
		scanf(" %s", MAP[i]);

	bool B = false, E = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (MAP[i][j] == 'B' && !B) {
				B = true;
				if (MAP[i][j + 1] == 'B') {
					q.push(pair(i, j + 1, 0, 0));
					visited[0][i][j + 1] = true;
					MAP[i][j] = MAP[i][j + 1] = MAP[i][j + 2] = '0';
				} else {
					q.push(pair(i + 1, j, 1, 0));
					visited[1][i + 1][j] = true;
					MAP[i][j] = MAP[i + 1][j] = MAP[i + 2][j] = '0';
				}
			}
			if (MAP[i][j] == 'E' && !E) {
				E = true;
				if (MAP[i][j + 1] == 'E') {
					dst = pair(i, j + 1, 0, -1);
					MAP[i][j] = MAP[i][j + 1] = MAP[i][j + 2] = '0';
				}
				else {
					dst = pair(i + 1, j, 1, -1);
					MAP[i][j] = MAP[i + 1][j] = MAP[i + 2][j] = '0';
				}
			}
		}
	}

	int ans = 0;
	while (!q.empty()) {
		pair cur = q.front();
		q.pop();

		if (cur.r == dst.r && cur.c == dst.c && cur.d == dst.d) {
			ans = cur.t;
			break;
		}

		for (int k = 0; k < 4; ++k) {
			int dr = cur.r + move_r[k];
			int dc = cur.c + move_c[k];
			if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
			if (visited[cur.d][dr][dc] || !can_I_go(dr, dc, cur.d)) continue;
			q.push(pair(dr, dc, cur.d, cur.t + 1));
			visited[cur.d][dr][dc] = true;
		}

		if (!visited[1 - cur.d][cur.r][cur.c] && cur.r > 0 && cur.r < N - 1 && cur.c > 0 && cur.c < N - 1) {
			bool check = false;
			for (int k = 0; k < 8; ++k) {
				int dr = cur.r + move_r[k];
				int dc = cur.c + move_c[k];
				check |= (MAP[dr][dc] - '0');
			}
			if (!check) {
				q.push(pair(cur.r, cur.c, 1 - cur.d, cur.t + 1));
				visited[1 - cur.d][cur.r][cur.c] = true;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}