#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;

const int NMAX  = 1e3 + 11;
const int MWMAX = 30 + 11;

int n, g;

int p[NMAX], w[NMAX], mem[NMAX][MWMAX];

int dp(int pos, int capacity)
{
    int &ans = mem[pos][capacity];

    if (pos == n)
        return 0;
    if (ans != -1)
        return ans;
    if (capacity - w[pos] >= 0)
        ans = dp(pos + 1, capacity - w[pos]) + p[pos];

    return (ans = max(ans, dp(pos + 1, capacity)));
}

int main(void)
{
    int t, mw;

    cin >> t;
    while (t--)
    {
        ll ans = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i] >> w[i];
        cin >> g;
        for (int i = 0; i < n; ++i)
            memset(mem[i], -1, MWMAX * sizeof(int));
        for (int i = 0; i < g; ++i)
        {
            cin >> mw;
            ans += dp(0, mw);
        }
        cout << ans << endl;
    }
    return 0;
}
