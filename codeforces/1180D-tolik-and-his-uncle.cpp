#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n / 2; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << i << " " << j << '\n';
            cout << n - i + 1 << " " << m - j + 1 << '\n';
        }
    }

    if (n & 1)
    {
        for (int j = 1; j <= m / 2; ++j)
        {
            cout << n / 2 + 1 << " " << j << '\n';
            cout << n / 2 + 1 << " " << m - j + 1 << '\n';
        }
        if (m & 1)
        {
            cout << n / 2 + 1 << " " << m / 2 + 1 << '\n';
        }
    }
    return 0;
}
