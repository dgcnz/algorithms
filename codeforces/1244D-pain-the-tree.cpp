#include <bits/stdc++.h>
#define sz(c) (int)c.size()
#define all(c) c.begin(), c.end()

using namespace std;
using ll = long long;
using vi = vector<int>;

int const NMAX = 1e5;
ll const  INF  = 1e17;

int n, c[3][NMAX];
vi  g[NMAX];

int main(void)
{
    int u, v;
    cin >> n;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    try
    {
        int leaf = distance(
            g, find_if(g, g + n, [](vi const &adj) { return sz(adj) == 1; }));

        vi a(n), p = {0, 1, 2};
        // dfs(leaf, -1, 0, a);

        int prv = -1, u = leaf;
        for (int i = 0; i < n; ++i)
        {
            a[i] = u;
            if (prv != -1)
                g[u].erase(find(all(g[u]), prv));

            if (sz(g[u]) > 1)
                throw -1;
            if (i < n - 1)
            {
                prv = u;
                u   = g[u].back();
            }
        }

        vector<vi> ps(6);
        int        k;
        ll         ans = INF;
        for (int i = 0; i < 6; ++i, next_permutation(all(p)))
        {
            ps[i]  = p;
            ll cur = 0;
            for (int j = 0; j < n; ++j)
                cur += c[p[j % 3]][a[j]];

            if (cur < ans)
            {
                ans = cur;
                k   = i;
            }
        }
        vi ansv(n);
        for (int i = 0; i < n; ++i)
            ansv[a[i]] = ps[k][i % 3] + 1;

        cout << ans << endl;
        for (int i = 0; i < n; ++i)
            cout << ansv[i] << " ";
        cout << endl;
    }
    catch (int e)
    {
        cout << e << endl;
    }

    return 0;
}
