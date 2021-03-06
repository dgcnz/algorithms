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

inline ll ceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, k;
        cin >> x >> y >> k;

        ll op1 = ceil(k * (y + 1) - 1, x - 1);
        ll op2 = k;
        cout << op1 + op2 << endl;
    }
    return 0;
}
