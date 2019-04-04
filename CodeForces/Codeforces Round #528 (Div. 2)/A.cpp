#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string str;
  cin >> str;

  vector<char> vec;
  int left = 0, right = str.size()-1;
  while (left <= right) {
    if ((right - left + 1) % 2) {
      vec.push_back(str[left]);
      ++left;
    } else {
      vec.push_back(str[right]);
      --right;
    }
  }

  for (int i=vec.size()-1; i>=0; i--) {
    cout << vec[i];
  }
  cout << '\n';
  return 0;
}