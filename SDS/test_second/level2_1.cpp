#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct item {
  int diff, start;
};

bool cmp(item a, item b) {
  return a.diff < b.diff;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T, N, M, B, pwr, num, sum;
  int P[20001];
  vector<item> vec;

  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cin >> N >> M >> B;
    memset(P, 0, sizeof(int) * 20001);
    sum = 0;
    vec.clear();

    for (int i = 0; i < M; ++i) {
      cin >> pwr >> num;
      P[pwr] = num;
      if (pwr >= B) 
        vec.push_back({pwr - B, pwr});
    }

    for (int i=1; i<B; ++i) {
      if (P[i]) {
        for (int j=i; j<B; ++j) {
          if (P[j] && i + j >= B) {
            vec.push_back({j + i - B, i});
          }
        }
      }
    }

    sort(vec.begin(), vec.end(), cmp);

    int len = vec.size(), num;
    for (int i = 0; i < len; ++i) {
      item &cur = vec[i];
      if (cur.start < B) {
        if (cur.start * 2 == cur.diff + B) num = P[cur.start]/2;
        else num = P[cur.start] < P[B - cur.start + cur.diff] ? P[cur.start] : P[B - cur.start + cur.diff];
      } else {
        num = P[cur.start];
      }

      if (!num) continue;

      if (N <= num) {
        sum += (N * (B + cur.diff));
        N = 0;
        break;
      } else {
        sum += (num * (B + cur.diff));
        N -= num;
        if (cur.start < B) {
          if (cur.start * 2 == cur.diff + B) P[cur.start] -= num * 2;
          else {
            P[cur.start] -= num;
            P[B - cur.start + cur.diff] -= num;
          }
        } else {
          P[cur.start] -= num;
        }
      }
    }

    cout << '#' << test_case << ' ';
    if (N > 0) cout << -1 << '\n';
    else cout << sum << '\n';
  }
}

// #include <iostream>
// #include <cstring>
// using namespace std;

// int main(int argc, char *argv[]) {
//   cin.tie(0);
//   ios_base::sync_with_stdio(false);

//   int T, N, M, B, pwr, num, sum; //, max_pwr;
//   int P[20001];

//   cin >> T;
//   for (int test_case = 1; test_case <= T; ++test_case) {
//     cin >> N >> M >> B;
//     memset(P, 0, sizeof(int) * (20001));
//     sum = 0;

//     for (int i = 0; i < M; ++i) {
//       cin >> pwr >> num;
//       P[pwr] = num;
//       // max_pwr = pwr > max_pwr ? pwr : max_pwr;
//     }

//     for (int diff = 0; B + diff <= 20000; ++diff) {
//       if (P[B + diff] >= N) {
//         sum += (N * (B + diff));
//         N = 0;
//         break;
//       } else if (P[B + diff]) {
//         sum += (P[B + diff] * (B + diff));
//         N -= P[B + diff];
//         P[B + diff] = 0;
//       }

//       bool isEnded = false;
//       for (int i = diff + 1; !isEnded && i < B; ++i) {
//         if (P[i] && P[B - i + diff]) {
//           if (2 * i == B + diff) {
//             if (P[i]/2 >= N) {
//               sum += (N * (B + diff));
//               N = 0;
//               isEnded = true;
//             } else {
//               sum += (P[i]/2 * (B + diff));
//               N -= (P[i] - P[i] % 2);
//               P[i] %= 2;
//             }
//             continue;
//           }

//           int min = P[i] < P[B - i + diff] ? P[i] : P[B - i + diff];
//           if (min >= N) {
//             sum += (N * (B + diff));
//             N = 0;
//             isEnded = true;
//           } else {
//             sum += (min * (B + diff));
//             N -= min;
//             P[i] -= min;
//             P[B - i + diff] -= min;
//           }
//         }
//       }
//       if (isEnded) break;
//     }

//     cout << '#' << test_case << ' ';
//     if (N) cout << -1 << '\n';
//     else cout << sum << '\n';
//   }

//   return 0;
// }