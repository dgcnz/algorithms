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

int n, sz[NMAX];
vi  g[NMAX];

void calc_sz(int u, int p = -1)
{
    sz[u] = 1;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        calc_sz(v, u - 1);
        sz[u] += sz[v];
    }
}

int main(void)
{
    cin >> n;
    for (int v = 1; v < n; ++v)
    {
        int u;
        cin >> u, u--;
        g[u].push_back(v);
    }

    calc_sz(0);
    for (int i = 0; i < n; ++i)
    {
        cout << sz[i] - 1 << " ";
    }
    cout << endl;

    return 0;
}
