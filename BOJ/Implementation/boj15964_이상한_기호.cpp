#include <iostream>
using namespace std;

int main(void)
{
    long a, b, res;
    cin >> a >> b;
    res = (a+b)*(a-b);
    cout << res << '\n';
    return 0;
}