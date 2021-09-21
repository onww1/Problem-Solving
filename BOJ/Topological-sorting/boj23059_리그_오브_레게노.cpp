#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second

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
typedef pair <int, pii> piii;
typedef tuple <int, int, int> ti3;

clock_t start_time, end_time;

void open() {
    TEST(freopen("input.txt", "r", stdin));
    TEST(freopen("output.txt", "w", stdout));
    TEST(freopen("debug.txt", "w", stderr));
    TEST(start_time = clock());
}

void close() {
    TEST(end_time = clock());
    TEST(printf("Total time : %Lf seconds\n", (long double)(end_time - start_time) / CLOCKS_PER_SEC));
}

const int MAX = 1e6 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int main(int argc, char *argv[]) {
    open();

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<string,int> item_to_id;
    vector<string> items;
    vector<vector<int>> edges;
    vector<int> deg;

    auto update = [&](string item) {
        if (item_to_id.count(item) == 0) {
            item_to_id[item] = items.size();
            items.push_back(item);
            edges.push_back(vector<int>());
            deg.push_back(0);
        }
    };

    string u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        update(u); update(v);
        edges[item_to_id[u]].push_back(item_to_id[v]);
        deg[item_to_id[v]]++;
    }

    int m = (int)items.size();
    vector<pair<int,string>> answer;

    queue<pii> q;
    for (int i = 0; i < m; i++) 
        if (deg[i] == 0) 
            q.emplace(0, i);

    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        answer.emplace_back(cur.X, items[cur.Y]);
        for (int next : edges[cur.Y]) 
            if (!--deg[next]) 
                q.emplace(cur.X + 1, next);
    }

    if (answer.size() < m) cout << "-1\n";
    else {
        sort(answer.begin(), answer.end());
        for (int i = 0; i < m; i++) cout << answer[i].Y << '\n';
    }

    close();
    return 0;
}