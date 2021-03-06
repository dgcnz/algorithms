#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
using iii = array<int, 3>;

int         n, m;
vector<iii> edges;
vector<int> visited;
const ll    INF = 1e17;

vector<int> bellman_ford(int src)
{
    int        x = -1;
    vector<ll> d(n + 1, INF);
    vector<ll> p(n + 1);
    d[src] = 0;

    for (int i = 1; i <= n; ++i)
    {
        bool change = false;
        for (auto [u, v, c] : edges)
        {
            if (d[u] < INF and d[u] + c < d[v])
            {
                visited[u] = visited[v] = true;
                change                  = true;
                d[v]                    = max(-INF, d[u] + c);
                p[v]                    = u;
                if (i == n)
                    x = v;
            }
        }
        if (not change)
            break;
    }

    if (x == -1)
    {
        return {};
    }
    else
    {

        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];
        vector<int> ans;

        int cur = y;
        do
        {
            ans.push_back(cur);
            cur = p[cur];
        } while (cur != y);
        ans.push_back(cur);
        reverse(ans.begin(), ans.end());
        return ans;
    }
}

vector<int> get_neg_cycle(void)
{
    for (int u = 1; u <= n; ++u)
    {
        if (not visited[u])
        {
            if (auto ans = bellman_ford(u); not ans.empty())
            {
                return ans;
            }
        }
    }
    return {};
}

int main(void)
{
    cin >> n >> m;

    edges.resize(m);
    visited.assign(n + 1, false);

    for (auto &[u, v, c] : edges)
        cin >> u >> v >> c;

    if (auto ans = get_neg_cycle(); not ans.empty())
    {
        cout << "YES" << endl;
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
