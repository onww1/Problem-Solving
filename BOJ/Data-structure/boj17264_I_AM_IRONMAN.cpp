#include <algorithm>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int N, P, W, L, G;
set <string> S;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> P >> W >> L >> G;
    for (int i = 0; i < P; ++i) {
        string name; char c;
        cin >> name >> c;
        if (c == 'W') S.insert(name);
    }
 
    int score = 0, flag = 0;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        if (S.count(name)) score += W;
        else score = max(0, score - L);
        if (score >= G) flag = 1;
    }

    if (flag) cout << "I AM NOT IRONMAN!!" << '\n';
    else cout << "I AM IRONMAN!!" << '\n';
    return 0;
}