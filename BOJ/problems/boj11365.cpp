#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str;

    while(true){
        getline(cin, str);
        if(str == "END") break;
        
        int len = str.length();
        for(int i=0; i<len/2 ; i++){
            char tmp = str[i];
            str[i] = str[len-1-i];
            str[len-1-i] = tmp;
        }
        cout << str << '\n';
    }
    
    return 0;
}