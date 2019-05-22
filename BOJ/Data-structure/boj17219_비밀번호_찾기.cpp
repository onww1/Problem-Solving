#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string, string> dic;
int N, M;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string link, pw;
        cin >> link >> pw;
        dic[link] = pw;
    }
    while (M--) {
        string link;
        cin >> link;
        cout << dic[link] << '\n';
    }
    return 0;
}