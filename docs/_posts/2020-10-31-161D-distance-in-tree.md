---
layout: post
mathjax: true
title: 161D Distance In Tree
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
int const NMAX = 5e4 + 11;
int const KMAX = 5e2 + 11;
int n, k, dp[NMAX][KMAX], cnt;
vi g[NMAX];
void dfs(int u, int p = -1)
{
    dp[u][0] = 1;
    for (auto v : g[u])
    {
        if (v != p)
        {
            dfs(v, u);
            for (int i = 1; i <= k; i++)
                cnt += dp[v][i - 1] * dp[u][k - i];
            for (int i = 1; i <= k; i++)
                dp[u][i] += dp[v][i - 1];
        }
    }
}
int main(void)
{
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << cnt << endl;
    return 0;
}

{% endraw %}
```