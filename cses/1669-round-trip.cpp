#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

const int NMAX = 1e5 + 11;

int n, m, tin[NMAX], cur_time;
vi  g[NMAX], ans;

bool dfs(int u, int p)
{
    if (tin[u] != 0)
    {
        ans.push_back(u);
        return true;
    }
    tin[u] = ++cur_time;

    for (auto v : g[u])
    {
        if (v == p)
            continue;

        if (dfs(v, u))
        {
            if (tin[u] >= tin[ans.front()])
                ans.push_back(u);
            return true;
        }
    }
    return false;
}

bool has_cycle(void)
{
    for (int u = 1; u <= n; ++u)
    {
        cur_time = 0;
        if (tin[u] == 0 and dfs(u, 0))
            return true;
    }
    return false;
}

int main(void)
{
    int u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (has_cycle())
    {
        cout << ans.size() << endl;
        for (auto u : ans)
            cout << u << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
