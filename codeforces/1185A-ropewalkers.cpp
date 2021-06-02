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
    vector<ll> a(3);
    ll         d;
    cin >> a[0] >> a[1] >> a[2] >> d;
    sort(all(a));

    ll ans = 0;
    ans += max(0LL, a[0] - (a[1] - d));
    ans += max(0LL, a[1] - (a[2] - d));
    cout << ans << endl;

    return 0;
}
