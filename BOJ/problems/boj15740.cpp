#include <iostream>
#include <string>
#include <vector>
using namespace std;

char abs(char a) {
	return a>0?a:-a;
}

void print(vector<char>& num, bool isMinus) {
	if (isMinus) cout << '-';
	for (int i=num.size()-1; i>=0; i--) {
		cout << (char)(abs(num[i]) + '0');
	}
	cout << '\n';
}

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string A, B;
	cin >> A >> B;

	int len1 = A.length();
	int len2 = B.length();

	int m1 = A[0] == '-' ? 1 : 0;
	int m2 = B[0] == '-' ? 1 : 0;

	int mul1 = m1 ? -1 : 1;
	int mul2 = m2 ? -1 : 1;

	vector<char> num1(len1);
	vector<char> num2(len2);

	for (int i=0; i<len1-m1; i++) {
		num1[i] = mul1 * (A[len1-1-i] - '0');
	} 
	for (int i=0; i<len2-m2; i++) {
		num2[i] = mul2 * (B[len2-1-i] - '0');
	}

	if (m1) len1--;
	if (m2) len2--;

	vector<char> res(len1>len2?len1+1:len2+1);

	int i = 0;
	while (i < len1 && i < len2) {
		res[i] = num1[i] + num2[i];
		i++;
	}
	while (i < len1) {
		res[i] = num1[i];
		i++;
	}
	while (i < len2) {
		res[i] = num2[i];
		i++;
	}

	while (i > 0 && res[i] == 0) i--;

	bool isMinus = false;
	if (res[i] < 0) isMinus = true;

	if (isMinus) {
		for (int j=0; j<=i; j++) {
			if (res[j] <= -10) {
				res[j] += 10;
				res[j+1] -= 1;
			}
			if (res[j] > 0) {
				res[j] -= 10;
				res[j+1] += 1;
			}
		}
	}
	else {
		for (int j=0; j<=i; j++) {
			if (res[j] >= 10) {
				res[j] -= 10;
				res[j+1] += 1;
			}
			if (res[j] < 0) {
				res[j] += 10;
				res[j+1] -= 1;
			}
		}
	}

	i = res.size() - 1;
	while (i > 0 && res.back() == 0) {
		res.pop_back();
		i--;
	}

	print(res, isMinus);

	return 0;
}