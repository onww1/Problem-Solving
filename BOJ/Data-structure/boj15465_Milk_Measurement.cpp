#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#define X first
#define Y second
using namespace std;

struct Log {
    int day, change;
    string name;
} logs[100];

int N, C, ans, val[101];
map <string, int> idx;
map <int, int> cnt;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> logs[i].day >> logs[i].name >> logs[i].change;
        int &ind = idx[logs[i].name];
        if (ind == 0) ind = ++C;
    }
    sort(logs, logs + N, [](const Log& a, const Log& b) { return a.day < b.day; });

    cnt[0] = C;
    for (int i = 0; i < N; ++i) {
        int &ind = idx[logs[i].name];

        bool prev_top = cnt.rbegin()->X == val[ind];
        int prev_top_cnt = cnt.rbegin()->Y;

        cnt[val[ind]]--;
        if (cnt[val[ind]] == 0) cnt.erase(val[ind]);
        val[ind] += logs[i].change;
        cnt[val[ind]]++;

        bool cur_top = cnt.rbegin()->X == val[ind];
        int cur_top_cnt = cnt.rbegin()->Y;

        if (cur_top) {
            if (!prev_top || prev_top_cnt != 1 || cur_top_cnt != 1) ans++;
        }
        else if (prev_top) ans++;
    }

    cout << ans << '\n';
    return 0;
}