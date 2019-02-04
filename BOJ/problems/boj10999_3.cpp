#include <cstdio>
#include <unistd.h>
#include <sys/syscall.h>
#include <algorithm>
typedef long long ll;
const int SZ = 1 << 20;
ll a[SZ], tree[2 * SZ], lazy[2 * SZ];

namespace FIO {
	const size_t BUFFER_SIZE = 1 << 20;
	char buffer[BUFFER_SIZE];
	char* ptr = buffer + BUFFER_SIZE;

	inline char readByte() {
		if (ptr == buffer + BUFFER_SIZE) {
			syscall(0x00, 0, buffer, BUFFER_SIZE);
			ptr = buffer;
		}
		return *ptr++;
	}

	int readInt() {
		int ret = 0;
		unsigned char c = readByte();
		while (c < '-') c = readByte();

		bool neg = false;
		if (c == '-') {
			neg = true;
			c = readByte();
		}
		while (c >= '0') {
			ret = ret * 10 + (c - '0');
			c = readByte();
		}
		return neg ? -ret : ret;
	}

  ll readLL() {
		ll ret = 0;
		unsigned char c = readByte();
		while (c < '-') c = readByte();

		bool neg = false;
		if (c == '-') {
			neg = true;
			c = readByte();
		}
		while (c >= '0') {
			ret = ret * 10 + (c - '0');
			c = readByte();
		}
		return neg ? -ret : ret;
	}

	char outbuf[BUFFER_SIZE >> 5];
	char* outp = outbuf;

	void printInt(int n) {
		if (n < 0) n = -n, *outp++ = '-';
		char *end = outp;
		do {
			*end++ = n % 10 + '0';
			n /= 10;
		} while (n);
		reverse(outp, end);
		*end++ = ' ';
		if (end < outbuf + BUFFER_SIZE) outp = end;
		else {
			syscall(0x01, 1, outbuf, end - outbuf);
			outp = outbuf;
		}
	}

  void printLL(ll n) {
		if (n < 0) n = -n, *outp++ = '-';
		char *end = outp;
		do {
			*end++ = n % 10 + '0';
			n /= 10;
		} while (n);
		reverse(outp, end);
		*end++ = ' ';
		if (end < outbuf + BUFFER_SIZE) outp = end;
		else {
			syscall(0x01, 1, outbuf, end - outbuf);
			outp = outbuf;
		}
	}

	void flush() {
		syscall(0x01, 1, outbuf, outp - outbuf);
	}
};

void lazy_update(int node, int start, int end) {
  if (lazy[node] != 0) {
    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void update_range(int node, int start, int end, int left, int right, ll diff) {
  lazy_update(node, start, end);
  if (end < left || right < start) return;
  if (left <= start && end <= right) {
    tree[node] += (end - start + 1) * diff;
    if (start != end) {
      lazy[node * 2] += diff;
      lazy[node * 2 + 1] += diff;
    }
  } else {
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, diff);
    update_range(node * 2 + 1, mid + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }
}

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = a[start];
  int mid = (start + end) / 2;
  return tree[node] = init(node * 2, start, mid) +
                      init(node * 2 + 1, mid + 1, end);
}

ll sum(int node, int start, int end, int left, int right) {
  lazy_update(node, start, end);
  if (end < left || right < start) return 0LL;
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) + 
         sum(node * 2 + 1, mid + 1, end, left, right);
}

int main(int argc, char *argv[]) {
  int n, m, k, i, x, y, z; ll w;
  n = FIO::readInt();
  m = FIO::readInt();
  k = FIO::readInt(); 
  m += k;
  for (i = 0; i < n; ++i) a[i] = FIO::readLL();
  init(1, 0, n-1);
  while (m--) {
    x = FIO::readInt();
    y = FIO::readInt();
    z = FIO::readInt();   
    if (x == 1) {
      w = FIO::readLL();
      update_range(1, 0, n-1, y-1, z-1, w);
    } else {
      FIO::printLL(sum(1, 0, n-1, y-1, z-1));
    }
  }
  FIO::flush();
  return 0;
}