#include <iostream>
using namespace std;  


int main() {
    int x = 27;
    int y = 27;

    string res = "";
    for (int i = 0; i < y; ++i) {
        for (int j = 0, c = '*'; j < x; ++j, c = '*') {
            if (((j / 3) & 1) ^ ((i / 3) & 1))
                c = ' ';

            res += (char)c;
        }

        res += '\n';
    }

    cout << res;
    cin.ignore();
    return 0;
}

