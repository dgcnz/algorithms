#include <bits/stdc++.h>

using namespace std;

bool ok(int n)
{
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            if (n == i * j)
                return true;
        }
    }
    return false;
}

int main(void)
{

    int n;
    cin >> n;

    cout << (ok(n) ? "Yes" : "No") << endl;

    return 0;
}
