#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printArr(vector<int>& arr, bool isReversed) {
	int len = arr.size();
	if (len == 0) {
		cout << "[]" << '\n';
	}
	else if (isReversed) {
		cout << '[' << arr[len-1];
		for (int i=len-2; i>=0; i--) {
			cout << ',' << arr[i];
		}
		cout << ']' << '\n';
	}
	else {
		cout << '[' << arr[0];
		for (int i=1; i<len; i++) {
			cout << ',' << arr[i];
		}
		cout << ']' << '\n';
	}
}

bool isNumeric(char c) {
	if ('0' <= c && c <= '9') return true;
	return false;
}

void parseData(vector<int>& arr, string data) {
	int num = 0;
	int len = data.length();
	bool isConsecutive = false;
	for (int i=1; i<len; i++) {
		if (!isNumeric(data[i])) {
			if (isConsecutive) num++;
			isConsecutive = false;
		}
		else {
			arr[num] = (arr[num] * 10) + data[i] - '0';
			isConsecutive = true;
		}
	}
}

int main(int argc, char const *argv[])
{
	int tc;
	cin >> tc;

	while (tc--) {
		int N;
		string input, data;
		cin >> input >> N >> data;

		vector<int> arr(N);
		parseData(arr, data);

		int len = input.length();
		int front = 0, back = 0;
		bool isReversed = false;

		for (int i=0; i<len; i++) {
			if (input[i] == 'R') 
				isReversed = !isReversed;
			else {
				if (isReversed) back++;
				else front++;
			}
		}

		if (front + back > N) cout << "error" << '\n';
		else {
			vector<int> subArr = vector<int>(arr.begin() + front, arr.end() - back);
			printArr(subArr, isReversed);
		}
	}

	return 0;
}