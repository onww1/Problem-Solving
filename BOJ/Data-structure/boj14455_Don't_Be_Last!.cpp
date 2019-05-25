#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define X first
#define Y second
using namespace std;

int N;
map <string, int> milk;
map <int, set<string>> r;
string s[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < 7; ++i) {
        milk[s[i]] = 0;
        r[0].insert(s[i]);
    }
    
    string name;
    int add;
    for (int i = 0; i < N; ++i) {
        cin >> name >> add;
        int &mil = milk[name];
        r[mil].erase(name);
        if (r[mil].empty())
            r.erase(mil);
        mil += add;
        r[mil].insert(name);
    }
    
    if (r.size() == 1 || (++r.begin())->Y.size() > 1)
        cout << "Tie" << '\n';
    else 
        cout << *((++r.begin())->Y.begin()) << '\n';
    
    return 0;
}