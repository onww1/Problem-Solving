#include <cstdio>
using namespace std;

char in[8][3];
int main(int argc, char *argv[]) {
  int i, j, k, l, cnt; bool isPossible = true;
  for (i = 0; i < 8; ++i) scanf(" %c %c %c", &in[i][0], &in[i][1], &in[i][2]);
  for (i = 0; i < 8; ++i) {
    for (j = 0; j < 3; ++j) {
      char ul = in[i][(j + 1) % 3];
      char ur = in[i][(j + 2) % 3];
      cnt = 0;
      for (k = 0; k < 8; ++k) {
        if (i == k) continue;
        for (l = 0; l < 3; ++l) {
          char ll = in[k][(l + 1) % 3];
          char lr = in[k][(l + 2) % 3];
          if (ul == lr && ur == ll) ++cnt;
        }
      }
      if (cnt != 1) isPossible = false;
    }
  }
  return !printf("%s\n", isPossible ? "YES" : "NO");
}

// #include <cstdio>
// #include <algorithm>
// #include <set>
// using namespace std;
// typedef pair<char,char> pcc;

// set <pcc> s;
// char in[8][3], visited[8], t, b;

// int find(int n, char d) {
//   for (int i = 0; i < 3; ++i) if (in[n][i] == d) return i;
//   return -1;
// }

// pcc mp(int n, int i, bool ccw) {
//   if (ccw) return {in[n][(i + 1) % 3], in[n][(i + 2) % 3]};
//   return {in[n][(i + 2) % 3], in[n][(i + 1) % 3]};
// }

// int main(int argc, char *argv[]) {
//   int i, j; bool isPossible = true;
//   for (i = 0; i < 8; ++i) {
//     scanf(" %c %c %c", &in[i][0], &in[i][1], &in[i][2]);
//     if (in[i][0] == in[i][1] || in[i][1] == in[i][2] || in[i][2] == in[i][0]) 
//       isPossible = false;
//   }

//   visited[0] = 1; t = in[0][0];
//   s.insert(mp(0, 0, true));

//   for (i = 1; i < 8; ++i) {
//     int idx = find(i, t);
//     if (idx == -1) continue;
//     visited[i] = true;
//     pcc p1 = mp(i, idx, true);
//     pcc p2 = mp(i, idx, false);
//     auto it1 = s.find(p1);
//     auto it2 = s.find(p2);
//     if (it1 != s.end() || it2 != s.end()) isPossible = false;
//     else s.insert(p1);
//   }

//   if (s.size() != 4) isPossible = false;

//   for (i = 1; i < 8; ++i) {
//     if (!visited[i]) {
//       visited[i] = true;
//       if (!b) {
//         for (j = 0; j < 3; ++j) {
//           pcc p = mp(i, j, false);
//           auto it = s.find(p);
//           if (it != s.end()) {
//             if (b) isPossible = false;
//             b = in[i][j];
//           }
//         }
//       }
      
//       int idx = find(i, b);
//       if (idx == -1) isPossible = false;
//       else {
//         pcc p1 = mp(i, idx, false);
//         pcc p2 = mp(i, idx, true);
//         auto it1 = s.find(p1);
//         auto it2 = s.find(p2);
//         if (it1 == s.end() || it2 != s.end()) isPossible = false;
//         else s.erase(p1);
//       }
//     }
//   }

//   return !printf("%s\n", isPossible ? "YES" : "NO");
// }