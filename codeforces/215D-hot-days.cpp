#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
using vll = vector<ll>;

ll iceil(ll a, ll b) { return (a + b - 1) / b; }

ll solve(
    int n, int m, vll const &t, vll const &T, vll const &x, vll const &cost)
{
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ll safe_children_per_bus = min(max(T[i] - t[i], 0LL), (ll)m);
        ll one = cost[i] + x[i] * (safe_children_per_bus == m ? 0 : m);
        if (safe_children_per_bus == 0 or safe_children_per_bus == m)
        {
            ans += one;
            continue;
        }
        ll nbuses = iceil(m, safe_children_per_bus);
        ll spaced = nbuses * cost[i];
        ans += min(one, spaced);
    }

    return ans;
}

int main(void)
{
    int n, m;
    vll t, T, x, cost;
    cin >> n >> m;

    t.resize(n), T.resize(n), x.resize(n), cost.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i] >> T[i] >> x[i] >> cost[i];

    cout << solve(n, m, t, T, x, cost) << endl;

    return 0;
}
