#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = c - a - b;
    if (d > 0 and d * d > 4 * a * b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
