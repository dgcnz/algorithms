#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 2e5 + 11;

ll n, a[NMAX], p[NMAX];

inline ll sum(int l, int r) { return p[r] - p[l - 1]; }

int main(void)
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], p[i] = a[i] + p[i - 1];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum(l, r) << endl;
    }
    return 0;
}
