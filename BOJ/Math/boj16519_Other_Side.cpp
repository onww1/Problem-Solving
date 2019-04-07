#include <cstdio>
int main(int argc, char *argv[]) {
  int w, s, c, k;
  scanf("%d %d %d %d", &w, &s, &c, &k);
  if (k && (s < k || (s == k && c + w <= 2 * k) || (s <= 2 * k && w + c <= k) || (s > 2 * k && w + c < k))) return !printf("YES\n");
  return !printf("NO\n");
}