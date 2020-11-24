---
layout: post
mathjax: true
title: 1133 - Tree Distances Ii
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int const NMAX = 2e5 + 11;
ll n, dp[NMAX], sz[NMAX], ans[NMAX];
vi g[NMAX];
void dfs(int u, int p = -1)
{
    sz[u] = 1;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + sz[v];
    }
}
void reroot(int u, int p = -1)
{
    ans[u] = dp[u];
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        auto temp1 = dp[v], temp2 = sz[v];
        dp[v] = dp[u] + sz[u] - 2 * sz[v];
        sz[v] = sz[u];
        reroot(v, u);
        dp[v] = temp1;
        sz[v] = temp2;
    }
}
int main(void)
{
    int root = 1;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(root);
    reroot(root);
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

{% endraw %}
```
</details>

