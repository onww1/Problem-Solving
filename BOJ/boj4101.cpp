#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll a, b;
    while (1) {
        cin >> a >> b;
        if (!a && !b) break;
        if (a > b) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}