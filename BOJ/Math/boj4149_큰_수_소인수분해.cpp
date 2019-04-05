/*
 *  I quoted BaaaaaaaaaaaarkingDog's code (10376021)
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull mul(ull x, ull y, ull m){
  return (ull)((__int128)x * y % m);
}

ull lpow(ull x, ull y, ull m){
  ull r = 1;
  x %= m;
  while(y){
    if(y&1) r = mul(r,x,m);
    x = mul(x,x,m);
    y >>= 1;
  }
  return r;
}

ull get_gcd(ull a, ull b) { return a % b ? get_gcd(b, a % b) : b; }

bool MR(ull n, ull a){
  if(n%a==0) return 0;
  int cnt = -1;
  ull d = n-1;
  while(!(d&1)){
    d >>= 1;
    cnt++;
  }
  ull p = lpow(a,d,n);
  if(p==1 or p==n-1) return 1;
  while(cnt--){
    p=mul(p,p,n);
    if(p==n-1) return 1;
  }
  return 0;
}

bool isPrime_MR(ll n){
  for(auto p : {2,3,5,7,11,13,17,19,23,29,31,37}){
    if(n == p) return 1;
    if(n > 40 && !MR(n,p)) return 0;
  }
  if(n <= 40) return 0;
  return 1;
}


ll PollardRho(ll n){
  ll x = rand()%(n-2)+2;
  ll y = x;
  ll c = rand()%(n-1)+1;
  while(true){
    x = (mul(x,x,n)+c)%n;
    y = (mul(y,y,n)+c)%n;
    y = (mul(y,y,n)+c)%n;
    ll d = get_gcd(abs(x-y),n);
    if(d == 1) continue;
    if(!isPrime_MR(d)) return PollardRho(d);
    else return d;
  }
}


void getFactor(ll n, vector<ll>& factors){
  while (n % 2 == 0){
    n >>= 1;
    factors.push_back(2);
  }
  if (n == 1) return;
  while(!isPrime_MR(n)){
    ll d = PollardRho(n);
    while(n%d == 0){
      factors.push_back(d);
      n /= d;
    }
    if(n == 1) break;
  }
  if(n != 1) factors.push_back(n);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
    
  ll N;
  cin >> N;
  if(N==1LL) return 0;
  vector <ll> factors;
  getFactor(N, factors);
  sort(factors.begin(), factors.end());
  for(auto e : factors) cout << e << '\n';
  return 0;
}

// #include <cstdio>
// #include <vector>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// vector <ll> factors;

// ll get_gcd(ll a, ll b) { return a % b ? get_gcd(b, a % b) : b; }
// ll get_abs(ll a) { return a < 0 ? -a : a; }
// ll multiply(ll p, ll q, ll m) {
//   p %= m, q %= m;
//   ll r = 0, w = p;
//   while (q) {
//     if (q % 2LL) r = (r + w) % m;
//     w = (w + w) % m;
//     q >>= 1LL;
//   }
//   return r;
// }

// ll pollard_rho(ll num) {
//   ll count, size = 2, factor = 1;
//   ll x[3] = {2, 2, 2}, y[3] = {2, 2, 2};
//   while (factor == 1) {
//       for (count = 1; (count <= size) && (factor <= 1); count++) {
//           x[0] = (multiply(x[0], x[0], num) + 1) % num;
//           factor = get_gcd(abs(x[0] - y[0]), num);
//           if (factor != 1) return factor;
//           x[1] = (multiply(x[1], x[1], num) - 1) % num;
//           factor = get_gcd(abs(x[1] - y[1]), num);
//           if (factor != 1) return factor;
//           x[2] = (multiply(x[2], x[2], num) + 2) % num;
//           factor = get_gcd(abs(x[2] - y[2]), num);
//       }
//       size = 2 * size;
//       y[0] = x[0], y[1] = x[1], y[2] = x[2];
//   }
//   return factor;
// }

// void get_factor(ll n) {
//   if (n == 1) return;

//   ll fac = pollard_rho(n);
//   if (fac == n) factors.push_back(n);
//   else {
//     get_factor(fac);
//     get_factor(n / fac);
//   }
// }

// int main (int argc, char *argv[]) 
// {
//   ll n, i;
//   scanf("%lld", &n);
//   for (i = 2LL; i <= n && i < 1000000;) {
//     if (n % i) ++i;
//     else factors.push_back(i), n /= i;
//   }
//   get_factor(n);
//   sort(factors.begin(), factors.end());
//   for (ll a : factors) printf("%lld\n", a);
//   return 0;
// }