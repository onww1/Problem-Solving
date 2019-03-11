#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for (int num : a) ans += num;
	return ans;
}

