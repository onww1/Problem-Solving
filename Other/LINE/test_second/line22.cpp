#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <string>
#include <vector>

using namespace std;

bool isSpace(char c) {
    if(c == ' ') return true;
    return false;
}

bool isNumber(char c) {
    if('0' <= c && c <= '9') return true;
    return false;
}

bool isPlusMinus(char c) {
    if(c == '+' || c == '-') return true;
    return false;
}

bool isMulDiv(char c) {
    if(c == '*' || c == '/') return true;
    return false;
}

bool isOpen(char c) {
    if(c == '(') return true;
    return false;
}

bool isClose(char c) {
    if(c == ')') return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    while (n-- > 0) {
        getline(cin, line);
        
        vector<int> numStack;
        vector<char> opStack;
        
        int len = line.length();
        for(int i=0; i<len; i++) {
            if(isSpace(line[i])) continue;
            else if(isNumber(line[i])) {
                int num = line[i++] - '0';
                for(; i<len && isNumber(line[i]); i++)
                    num = (num * 10) + line[i] - '0';
                numStack.push_back(num);

                if(!opStack.empty() && isMulDiv(opStack.back())){
                    int num1 = numStack.back();
                    numStack.pop_back();
                    int num2 = numStack.back();
                    numStack.pop_back();
                    char op = opStack.back();
                    opStack.pop_back();
                    if(op == '+') numStack.push_back(num2 + num1);
                    else if(op == '-') numStack.push_back(num2 - num1);
                    else if(op == '*') numStack.push_back(num2 * num1);
                    else if(op == '/') numStack.push_back(num2 / num1);
                }
            }
            else if(isPlusMinus(line[i])) {
                opStack.push_back(line[i]);
            }
            else if(isMulDiv(line[i])) {
                opStack.push_back(line[i]);
            }
            else if(isOpen(line[i])) {
                opStack.push_back(line[i]);
            }
            else if(isClose(line[i])) {
                while(opStack.back() != '(') {
                    int num1 = numStack.back();
                    numStack.pop_back();
                    int num2 = numStack.back();
                    numStack.pop_back();
                    char op = opStack.back();
                    opStack.pop_back();

                    if(!opStack.empty() && opStack.back() == '-') {
                        num2 *= -1;
                        opStack.pop_back();
                        opStack.push_back('+');
                    }

                    if(op == '+') numStack.push_back(num2 + num1);
                    else if(op == '-') numStack.push_back(num2 - num1);
                    else if(op == '*') numStack.push_back(num2 * num1);
                    else if(op == '/') numStack.push_back(num2 / num1);
                }
                opStack.pop_back();

                if(!opStack.empty() && isMulDiv(opStack.back())) {
                    int num1 = numStack.back();
                    numStack.pop_back();
                    int num2 = numStack.back();
                    numStack.pop_back();
                    char op = opStack.back();
                    opStack.pop_back();

                    if(!opStack.empty() && opStack.back() == '-') {
                        num2 *= -1;
                        opStack.pop_back();
                        opStack.push_back('+');
                    }

                    if(op == '+') numStack.push_back(num2 + num1);
                    else if(op == '-') numStack.push_back(num2 - num1);
                    else if(op == '*') numStack.push_back(num2 * num1);
                    else if(op == '/') numStack.push_back(num2 / num1);
                }
            }
        }
        while(!opStack.empty()){
            int num1 = numStack.back();
            numStack.pop_back();
            int num2 = numStack.back();
            numStack.pop_back();
            char op = opStack.back();
            opStack.pop_back();
            
            if(!opStack.empty() && opStack.back() == '-') {
                num2 *= -1;
                opStack.pop_back();
                opStack.push_back('+');
            }

            if(op == '+') numStack.push_back(num2 + num1);
            else if(op == '-') numStack.push_back(num2 - num1);
            else if(op == '*') numStack.push_back(num2 * num1);
            else if(op == '/') numStack.push_back(num2 / num1);
        }

        cout << numStack.back() << '\n';
    }
    return 0;
}