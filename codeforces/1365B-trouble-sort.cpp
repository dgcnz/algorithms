#include <bits/stdc++.h>

using namespace std;

const int NMAX = 5e2 + 11;
int       n, a[NMAX];
bool      b[NMAX];

bool sorted(void)
{
    for (int i = 1; i < n; ++i)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

bool solve(void)
{
    if (sorted())
        return true;

    int zeros, ones;
    zeros = ones = 0;

    for (int i = 0; i < n; ++i)
    {
        if (b[i])
            ones += 1;
        else
            zeros += 1;
    }
    if (zeros > 0 and ones > 0)
        return true;
    else
        return false;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}
