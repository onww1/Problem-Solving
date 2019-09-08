#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#define X first
#define Y second
using namespace std;
typedef long double ldb;

map <string, int> mp;
int cnt = 0;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while (getline(cin, s)) cnt++, mp[s]++;
    cout << fixed;
    cout.precision(4);
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << it->X << ' ' << ((ldb)(it->Y * 100)/ cnt ) << '\n';
    }

    return 0;
}