#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> urlParsing(string url) {
	vector<string> urlData;
	stringstream ss(url);
	string api, userid, data;
	getline(ss, api, '/'); //drop
	getline(ss, api, '/');
	getline(ss, userid, '/');
	getline(ss, data);
	urlData.push_back(api);
	urlData.push_back(userid);
	urlData.push_back(data);
	return urlData;
}

int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);  // drop a newline traling n
    while (n-- > 0) {
				getline(cin, line);
        stringstream ss(line);
        string method, url, body;
        getline(ss, method, ' ');
        getline(ss, url, ' ');
        getline(ss, body);
        // @todo Write your code here.
				
				ve
				
    }
    return 0;
}

