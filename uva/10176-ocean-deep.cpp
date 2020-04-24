#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const int MOD = 131071;

int main(void)
{
    char b;
    int  rem = 0;

    while (cin.get(b))
    {
        if (b == '#')
        {
            cout << ((rem % MOD) == 0 ? "YES" : "NO") << endl;
            rem = 0;
        }
        else if (b == '0' or b == '1')
            rem = ((rem << 1) + (b - '0')) % MOD;
        else
            continue;
    }

    return 0;
}
