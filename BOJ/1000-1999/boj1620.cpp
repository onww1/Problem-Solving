#include <string>
#include <iostream>
#include <map>
using namespace std;

map <string,int> name_to_id;
map <int,string> id_to_name;
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m, i;
  string str;

  cin >> n >> m;
  for (i = 1; i <= n; ++i) {
    cin >> str;
    name_to_id.insert({str, i});
    id_to_name.insert({i, str});
  }
  for (i = 0; i < m; ++i) {
    cin >> str;
    if ('0' <= str[0] && str[0] <= '9') {
      int id = 0;
      for (int j = 0; j < str.size(); ++j) id = id * 10 + str[j] - '0';
      cout << id_to_name[id] << '\n';
    } else {
      cout << name_to_id[str] << '\n';
    }
  }
  return 0;
}